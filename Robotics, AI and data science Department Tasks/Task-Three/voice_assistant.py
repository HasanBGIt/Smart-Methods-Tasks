from RealtimeSTT import AudioToTextRecorder
from RealtimeTTS import TextToAudioStream, SystemEngine
import cohere
import signal
import sys
import os
import logging
import contextlib
import io

os.environ["CTRANSLATE2_LOG_LEVEL"] = "ERROR"
logging.getLogger('ctranslate2').setLevel(logging.ERROR)

# Set up Cohere API
COHERE_API_KEY = os.getenv("COHERE_API_KEY", "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX")
conversation_id = "english-voice-user-1"
co = cohere.Client(COHERE_API_KEY)

# Text-to-Speech
engine = SystemEngine()
stream = TextToAudioStream(
    engine=engine,
    muted=False,
    on_audio_stream_start=lambda: print("\n[Alexa] Reading response..."),
    on_audio_stream_stop=True
)

# speech-to-text
def on_final_text(text):
    if text.strip():
        print(f"\n You said: {text}")
        send_to_cohere(text)

# Generate reply using Cohere
def send_to_cohere(message): 
    prompt = f"{message.strip()}\nPlease respond in English only."
    
    try:
        response = co.chat(
            message=prompt,
            model="command-r-plus",
            conversation_id=conversation_id
        )
        reply = response.text.strip()
        print(f"\n[Cohere Response] {reply}")
        stream.feed(reply)
        with contextlib.redirect_stdout(io.StringIO()):
            stream.play()
    except Exception as e:
        print(f" Failed to contact Cohere: {e}")

# Graceful shutdown
def shutdown_handler(sig, frame):
    print("\n Shutting down assistant...")
    recorder.shutdown()
    sys.exit(0)

signal.signal(signal.SIGINT, shutdown_handler)
signal.signal(signal.SIGTERM, shutdown_handler)


if __name__ == '__main__':
    recorder = AudioToTextRecorder(
        language='en',
        model='small',
        wakeword_backend="pvporcupine",
        wake_words="alexa", 
        enable_realtime_transcription=True,
        on_recording_start=lambda: print("\n Listening..."),
        on_recording_stop=lambda: True,
        on_wakeword_detected=lambda: print("\n You can speak now.")
    )

    print("\n=== Alexa Assistant is ready ===")
    print("Say 'Alexa' and then ask your question in English.")
    while True:
        recorder.text(on_final_text)

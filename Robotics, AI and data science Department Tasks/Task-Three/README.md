# Task Overview

In this project, I built a **voice assistant** that converts live audio into text, uses a Large Language Model (LLM) to generate a response, and then converts that response back to audio. The system runs in real time.

---

## Demo Video
https://github.com/user-attachments/assets/f50d76ff-93fc-4c6d-ad6a-a6ea8347b5f9

---
## 1. Audio-to-Text 

- Implemented using `RealtimeSTT` with Whisper (small model)
- Wake-word detection using ("Alexa")
- Once triggered, records and transcribes the user's voice input into English text.
  
---

## 2. LLM Integration

- The text is sent to **Cohere's command-r-plus model**
- A concise, intelligent response is generated in **English only**
- The assistant can be instructed to respond briefly using prompt customization.

---

## 3. Text-to-Audio 

- Implemented using `RealtimeTTS` and `SystemEngine` for speech playback
- The generated response is played back to the user using the system's audio.

---

## Author
**Hassan**  
🌐 [My Website](https://hsnhb.social/)  
🔗 [GitHub](https://github.com/HasanBGIt)  
🔗 [LinkedIn](https://www.linkedin.com/in/hsnhb/)  

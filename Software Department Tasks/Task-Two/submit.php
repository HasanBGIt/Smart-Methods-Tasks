<?php
include 'connect.php';

if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $name = trim($_POST["name"]);
    $age = (int)$_POST["age"];

    if (!empty($name) && $age > 0) {
        $stmt = $conn->prepare("INSERT INTO users_info (name, age) VALUES (?, ?)");
        $stmt->bind_param("si", $name, $age);
        $stmt->execute();
        $stmt->close();
    }


    header("Location: index.php"); 
    exit();
}
?>

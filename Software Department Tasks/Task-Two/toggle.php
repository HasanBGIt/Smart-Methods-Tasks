<?php
include 'connect.php';

if ($_SERVER["REQUEST_METHOD"] === "POST" && isset($_POST["id"])) {
    $id = (int)$_POST["id"];

    $result = $conn->query("SELECT status FROM users_info WHERE id = $id");
    if ($result && $row = $result->fetch_assoc()) {
        $currentStatus = $row["status"];
        $newStatus = ($currentStatus == 1) ? 0 : 1;

        $conn->query("UPDATE users_info SET status = $newStatus WHERE id = $id");
    }
}

header("Location: index.php"); 
exit();
?>

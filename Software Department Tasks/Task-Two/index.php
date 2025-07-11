<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>User Info</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <section>
        <h2>Add New User</h2>
        <form action="submit.php" method="post">
            <label >Name:</label>
            <input type="text" id="name" name="name" required>

            <label >Age:</label>
            <input type="number" id="age" name="age" required>

            <input type="submit" value="Submit">
        </form>
    </section>

    <section>
        <h2>User List</h2>
        <?php include 'list.php'; ?>
    </section>

</body>
</html>

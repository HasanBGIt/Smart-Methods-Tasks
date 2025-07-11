<?php
include 'connect.php';
echo '<table>';
echo '<tr><th>ID</th><th>Name</th><th>Age</th><th>Status</th><th>Action</th></tr>';

$result = $conn->query("SELECT * FROM users_info");

while ($row = $result->fetch_assoc()):
?>
<tr>
    <td><?= $row['id'] ?></td>
    <td><?= htmlspecialchars($row['name']) ?></td>
    <td><?= $row['age'] ?></td>
    <td><?= $row['status'] ?></td>
    <td>
        <form action="toggle.php" method="post" >
            <input type="hidden" name="id" value="<?= $row['id'] ?>">
            <button class="toggle-btn" type="submit">Toggle</button>
        </form>
    </td>
</tr>
<?php endwhile;

echo '</table>';
?>

<?php 

if (isset($_GET['id'])) {
	include "db_conn.php";

	function validate($data){
        $data = trim($data);
        $data = stripslashes($data);
        $data = htmlspecialchars($data);
        return $data;
	}

	$id = validate($_GET['id']);

	$sql = "SELECT * FROM users WHERE id=$id";
    $result = mysqli_query($conn, $sql);

    if (mysqli_num_rows($result) > 0) {
    	$row = mysqli_fetch_assoc($result);
    }else {
    	header("Location: read.php");
    }


}else if(isset($_POST['update'])){
    include "../db_conn.php";
    function validate($data){
        $data = trim($data);
        $data = stripslashes($data);
        $data = htmlspecialchars($data);
        return $data;
	}

	$department = validate($_POST['department']);
	$email = validate($_POST['email']);
    $job = validate($_POST['job']);
    $requisition = validate($_POST['requisition']);
	$id = validate($_POST['id']);

	if (empty($department)) {
		header("Location: ../update.php?id=$id&error=Department is required");
	}else if (empty($email)) {
		header("Location: ../update.php?id=$id&error=Email is required");
	}
    else if (empty($job)) {
        header("Location: ../update.php?id=$id&error=Job is required");
    }
    else if (empty($requisition)) {
        header("Location: ../update.php?id=$id&error=Requisition is required");
    }
    else {

       $sql = "UPDATE users
               SET department='$department', email='$email', job='$job', requisition='$requisition'
               WHERE id=$id ";
       $result = mysqli_query($conn, $sql);
       if ($result) {
       	  header("Location: ../read.php?success=successfully updated");
       }else {
          header("Location: ../update.php?id=$id&error=unknown error occurred&$user_data");
       }
	}
}else {
	header("Location: read.php");
}
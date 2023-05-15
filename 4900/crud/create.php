<?php 

if (isset($_POST['create'])) {
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

	$user_data = 'department='.$department. 'email='.$email. 'job='.$job. 'requisition='.$requisition;
   
	if (empty($department)) {
		header("Location: ../index.php?error=Department is required&$user_data");
	}else if (empty($email)) {
		header("Location: ../index.php?error=Email is required&$user_data");
	}
	else if (empty($job)) {
		header("Location: ../index.php?error=Job is required&$user_data");
	}
	else if (empty($requisition)) {
		header("Location: ../index.php?error=Requisition is required&$user_data");
	}else {

       $sql = "INSERT INTO users(department, email, job, requisition) 
               VALUES('$department', '$email', '$job', '$requisition')";
       $result = mysqli_query($conn, $sql);
       if ($result) {
       	  header("Location: ../read.php?success=successfully created");
       }else {
          header("Location: ../index.php?error=unknown error occurred&$user_data");
       }
	}

}
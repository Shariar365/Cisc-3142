<?php include "php/read.php"; ?>
<!DOCTYPE html>
<html>
<head>
	<title>Printworks</title>
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
</head>
<body>
     
	<div class="container">

	<div class="box">

			<h4 class="display-4 text-center" style="background-color:gray; color: white;">Customer orders</h4><br>
			<div class="link-right">
				<a href="sort.php" class="link-primary" >Sort</a>
			</div>
			<?php if (isset($_GET['success'])) { ?>
		    <div class="alert alert-success" role="alert">
			  <?php echo $_GET['success']; ?>
		    </div>
		    <?php } ?>
			<?php if (mysqli_num_rows($result)) { ?>
			<table class="table table-striped">
			  <thead>
			    <tr>
			      <th scope="col">ID</th>
			      <th scope="col">Department</th>
			      <th scope="col">Email</th>
			      <th scope="col">Job</th>
			      <th scope="col">Requisition</th>
			      <th scope="col">Action</th>
			    </tr>
			  </thead>
			  <tbody>
			  	<?php 
			  	   $i = 0;
			  	   while($rows = mysqli_fetch_assoc($result)){
			  	   $i++;
			  	 ?>
			    <tr>
			      <th scope="row"><?=$i?></th>
			      <td><?=$rows['department']?></td>
			      <td><?php echo $rows['email']; ?></td>
			      <td><?php echo $rows['job']; ?></td>
			      <td><?php echo $rows['requisition']; ?></td>
			      <td><a href="update.php?id=<?=$rows['id']?>" 
			      	     class="btn btn-success">Update</a>

			      	  <a href="php/delete.php?id=<?=$rows['id']?>" 
			      	     class="btn btn-danger">Delete</a>
			      </td>
			    </tr>
			    <?php } ?>
			  </tbody>
			</table>
			<?php } ?>
			<div class="link-right">
				<a href="index.php" class="link-primary">Create</a>
			</div>
			<div class="link-right">
				<a href="search.php" class="link-primary">Search</a>
			</div>
		</div>
	</div>
</body>
</html>
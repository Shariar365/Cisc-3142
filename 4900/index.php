<!DOCTYPE html>
<html>
<head>
	<title>Printworks</title>
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
</head>
<body>
	<div class="container">

		<form action="php/create.php" 
		      method="post">
            
		   <h4 class="display-4 text-center" style="background-color:gray; color: white;">Create</h4><hr><br>
		   <?php if (isset($_GET['error'])) { ?>
		   <div class="alert alert-danger" role="alert">
			  <?php echo $_GET['error']; ?>
		    </div>
		   <?php } ?>
		   <div class="form-group">
		     <label for="name">Department</label>
		     <input type="name" 
		           class="form-control" 
		           id="department" 
		           name="department" 
		           value="<?php if(isset($_GET['department']))
		                           echo($_GET['department']); ?>" 
		           placeholder="Enter department">
		   </div>

		   <div class="form-group">
		     <label for="email">Email</label>
		     <input type="email" 
		           class="form-control" 
		           id="email" 
		           name="email" 
		           value="<?php if(isset($_GET['email']))
		                           echo($_GET['email']); ?>"
		           placeholder="Enter email">
		   </div>
		   
		    <div class="form-group">
		     <label for="job">Job</label>
		     <input type="name" 
		           class="form-control" 
		           id="job" 
		           name="job" 
		           value="<?php if(isset($_GET['job']))
		                           echo($_GET['job']); ?>"
		           placeholder="Enter job">
		   </div>

		    <div class="form-group">
		     <label for="requisition">Requisition</label>
		     <input type="number" 
		           class="form-control" 
		           id="requisition" 
		           name="requisition" 
		           value="<?php if(isset($_GET['requisition']))
		                           echo($_GET['requisition']); ?>"
		           placeholder="Enter requisition">
		   </div>

		   <button type="submit" 
		          class="btn btn-primary"
		          name="create">Create</button>
		    <a href="read.php" class="link-primary">Back</a>
	    </form>
	</div>
</body>
</html>
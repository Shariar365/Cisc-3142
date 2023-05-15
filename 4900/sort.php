<!DOCTYPE html>
<html>
<head>
	<title>Printworks</title>
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
</head>
<body>

<div class="container">
        <div class="row">
            <div class="col-md-12">
                <div class="card mt-4">
                </div>
            </div>

            <div class="col-md-12">
                <div class="card mt-4">
                    <div class="card-body">
                        <table class="table table-bordered">
                            <thead>
                                <tr>
                                    <th>Department</th>
                                    <th>Email</th>
                                    <th>Job</th>
                                    <th>Requisition</th>
                                
                                </tr>
                            </thead>
                            <tbody>
                            <?php
                          
                               $con = mysqli_connect("localhost","root","","my_db2");
 
                            // Check connection
                           if($con === false){
                              die("ERROR: Could not connect. " . mysqli_connect_error());
                           }
 
                           // Attempt select query execution with order by clause
                          $query = "SELECT * FROM users ORDER BY requisition";
                          if($result = mysqli_query($con, $query)){
                          if(mysqli_num_rows($result) > 0){
                          
                          while($row = mysqli_fetch_array($result)){
                          echo "<tr>";
                          echo "<td>" . $row['department'] . "</td>";
                          echo "<td>" . $row['email'] . "</td>";
                          echo "<td>" . $row['job'] . "</td>";
                          echo "<td>" . $row['requisition'] . "</td>";
                          echo "</tr>";
                          }
                         
                        // Close result set 
                        mysqli_free_result($result); 
                    }
                       else{ 
                        echo "No records matching your query were found.";
                    }
                }
                    else{
                        echo "ERROR: Could not able to execute $sql. " . mysqli_error($con);
                    }
                    // Close connection
                    mysqli_close($con);
                ?>
                            </tbody>
                        </table>
                    </div>
                </div>
            </div>
        </div>
        <a href="read.php" class="link-primary">Back</a>
    </div>
</body>
</html>
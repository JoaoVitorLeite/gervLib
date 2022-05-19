args <- commandArgs(trailingOnly = TRUE)

#numberOfElements = "all" or number
intrinsic_dim <- function(datasetPath, separator, numberOfElements, distanceFunction, numberOfThreads=12){

  library("parallelDist")
  
  data <- read.csv(datasetPath, sep = separator)
  
  if(numberOfElements != "all"){
    
    num <- min(as.numeric(numberOfElements), nrow(data))
    data <- data[0:num,]
    
  }
  
  mat <- as.matrix(parallelDist(as.matrix(data), method = distanceFunction, threads=as.numeric(numberOfThreads)))
  
  mean_values <- mean(mat)
  std_values <- sd(mat)
  ans <- (mean_values*mean_values)/(2*std_values*std_values)
  
  if(ans < 2){
    ans <- 2
  }

  if(ans > ncol(data)){
    ans <- ncol(data)
  }
  
  return(ans)
  
}

if(length(args) > 4){

  intrinsic_dim(args[1], args[2], args[3], args[4], args[5])

}else{

  intrinsic_dim(args[1], args[2], args[3], args[4])

}
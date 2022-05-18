
#Split 0.9/0.1 => Train/Test
split <- function(pathOfDataset, separator, seed = 100, trainFileName, testFileName)
{

  data <- read.csv(pathOfDataset, sep = separator)
  set.seed(seed) 
  sample <- sample.int(n = nrow(data), size = floor(.9*nrow(data)), replace = F)
  train <- data[sample, ]
  test  <- data[-sample, ]  
  
  write.table(train, file = trainFileName, sep = ",", col.names = FALSE, row.names = FALSE)
  write.table(test, file = testFileName, sep = ",", col.names = FALSE, row.names = FALSE)
  
}


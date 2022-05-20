
sample_dataset <- function(filePath, separator, sizeOfSample, sampleFileName = "sample.csv", seed = 100){
  
  set.seed(100)
  df <- data.frame(read.csv(filePath, sep = separator, header=F))
  df <- df[sample(nrow(df), sizeOfSample), ]
  write.table(df, file=paste0(getwd(), "/", sampleFileName), sep=",", row.names = F, col.names = F)

}
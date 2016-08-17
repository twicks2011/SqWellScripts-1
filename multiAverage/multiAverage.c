#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[] )
{

  char masterWeightFile[400];
  
  //===Masterfile variables====
  int numTemps;
  char configsInput[400];
    char outputDir[400];
    //char weightFile[100];
  char VMDdir[400];
  char initCoords[400];
  char tempsFile[400];
  double LAMBDA;
  char moveSizesDir[400];
  FILE *inputPtr;
    double PHI_MAX;
  double ALPHA;
  double BETA;
  double GAMMA;
   int TEMP_INTEREST;
   int fileInput;
     char buffer[400];
     double sigma;
  int stretchStart;
  int stretchFinish;
 int Nmin;
  int Nmax;
  double kappa;
  double kappaRHS;
  double PRINT_INTERVAL;
  double PHI_UPDATE_INTERVAL;
  double UPDATE_INTERVAL;
  double SWAP_INTERVAL;
  int NUM_SWAPS;
  double NUM_SWAP_INTERVALS;
  double RESET_INTERVAL;
  double SMALL_ANGLE_MOVES;
  double REPTATION_MOVES;
  double CRANK_MOVES;
  double END_ROT_MOVES;
  double END_BRIDGE_MOVES;
    int update;
  double tolerance;
  int FLAG;
  int fileNumber;
  int NBeads;

  
  char sdir[400];
  char wdir[400];
  char ddir[400];
  char newWeightFile[400];
  char traceFile[400];

  
  //====Original variables
  char sdirTEMP[400], ddirTEMP[400], weightFileTEMP[400], weightFile[400], newWeightFileTEMP[400];
  int num_blocks;
  int N, matchPoint;
  int i, j, n;
  int startPoint;

  long unsigned int occupanciesTEMP[18][1000]={0};
    long unsigned int occupancies[18][1000]={0};

    FILE  *weightPtr;
    char blockFile[400];
    double bias[1000];


  //====Check correct at least 4 args and that arg number is even ================
  FLAG=0;
  if(argc < 6){
    printf("Not enough arguments\n");
    FLAG=1;
  }


  if ((argc) % 2){
    printf("Number of arguments, %d, is even. This should be odd.\n", argc-1);
    FLAG=1;
  }

  
  if(FLAG==1){
    printf("Averages over n runs of the sqWell code. All runs must have the same weight file or will be refused.\n");
    printf("Usage: multiAverage  [int matchPoint][int NMax][input filename 1][int startPoint 1]...[input filename n][int startPoint n]\n");
    exit(EXIT_FAILURE);
  }

  matchPoint = atoi( argv[1]);
  N= atoi( argv[2]);

  printf("matchpoint=%d, Nmax=%d\n",matchPoint, N);
  //return 0;

  

  //====Loop over input files==========
  for(fileNumber=2;   fileNumber<= (argc-1)/2 ; fileNumber++){
    printf("%s %s\n",argv[fileNumber*2-1], argv[fileNumber*2] );
    
    
    if((inputPtr = fopen(argv[fileNumber*2-1],"r")) == NULL){
      printf("Cannot open file %s\n",argv[fileNumber*2-1]);
      exit(EXIT_FAILURE);
    }
    
 


    
    //====Read in the input file====================================
    printf("Reading from the input file: %s\n", argv[fileNumber*2-1]);
    fscanf(inputPtr, "%d\n", &NBeads);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%lf\n", &LAMBDA);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%d\n", &TEMP_INTEREST);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%d\n", &numTemps);
    fgets(buffer, 100, inputPtr);
    //fscanf(inputPtr, "%lf\n", &RAT);
    fscanf(inputPtr, "%s\n", tempsFile);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%d\n", &fileInput);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%s\n", configsInput);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%s\n",moveSizesDir);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%lf\n", &PHI_MAX);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%lf\n", &ALPHA);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%lf\n", &BETA);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%lf\n", &GAMMA);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%lf\n", &sigma);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%d\n", &stretchStart);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%d\n", &stretchFinish);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%d\n", &Nmin);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%d\n", &Nmax);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%lf\n", &kappa);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%lf\n", &kappaRHS);
    fgets(buffer, 100, inputPtr);
    //fscanf(inputPtr, "%s\n", updateInfoDir);
    //fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%d\n", &update);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%lf\n", &tolerance);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%le\n", &PRINT_INTERVAL);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%le\n", &PHI_UPDATE_INTERVAL);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%le\n", &UPDATE_INTERVAL);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%le\n", &SWAP_INTERVAL);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%d\n", &NUM_SWAPS);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%le\n", &NUM_SWAP_INTERVALS);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%le\n", &RESET_INTERVAL);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%lf\n", &SMALL_ANGLE_MOVES);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%lf\n", &REPTATION_MOVES);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%lf\n", &CRANK_MOVES);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%lf\n", &END_ROT_MOVES);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%lf\n", &END_BRIDGE_MOVES);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%s\n",outputDir);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%s\n",weightFile);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%s\n",VMDdir);
    fgets(buffer, 100, inputPtr);
    fscanf(inputPtr, "%s\n",initCoords);
    fgets(buffer, 100, inputPtr);
    fclose(inputPtr);
    

    //check that the weightFiles are all the same
    if(fileNumber == 2){
      strcpy(masterWeightFile, weightFile);
    }else{
      //      printf("Comparing %s and %s\n",weightFile, masterWeightFile);
      if( strcmp(masterWeightFile,weightFile) != 0 ){
	printf("Weight files don't agree for file %d!!!!!!!!!!!!!\n%s \n%s \n",
	       fileNumber*2-1,masterWeightFile, weightFile);
	exit( EXIT_FAILURE);
      }
    }



    printf("%d %s %s\n", fileNumber*2-1, masterWeightFile, weightFile);

  

    //convert command line arguments to integers
    num_blocks= 1000000000;
    startPoint= atoi( argv[fileNumber*2]);
    
    printf("Start point=%d\n",startPoint);
    
    
    sprintf(sdirTEMP,"%s" ,outputDir);
    
    




    //====================Trim down the new weight file folder path====================

    sprintf(newWeightFileTEMP,"%s",argv[fileNumber*2 - 1]);
    for(i = 1  ;   i <= 11   ;   i++)
      memmove(newWeightFileTEMP, newWeightFileTEMP+1, strlen(newWeightFileTEMP));
    //sprintf(newWeightFileTEMP,"outputFiles/weightFiles/%s",argv[1]);
    printf("Created new weight file string as: %s\n",newWeightFileTEMP);
    printf("%d %s %s\n", fileNumber*2-1, masterWeightFile, weightFile);

  
    //Summarise the input file to the screen
    sprintf(sdir,"%s/",sdirTEMP);
    sprintf(wdir,"%s/",sdirTEMP);
    // sprintf(ddir,"%s/",ddirTEMP);
    sprintf(ddir,"%s/collated/",sdirTEMP);
    //sprintf(newWeightFile,"outputFiles/weightFiles/%s",newWeightFileTEMP);
    sprintf(newWeightFile,"dummy.dat");
    

    printf("Source directory: %s\n", sdir);
    printf("Working directory: %s\n", wdir);
    printf("Number of blocks: %d\n", num_blocks);
    printf("Max no. of states: %d\n",N);
    printf("Weight File for correction: %s\n",weightFile);
    printf("New weight file: %s\n",newWeightFile);
    printf("Number of Temps = %d\n",numTemps);


    


    //printf("Nmax=%d\n",N);

    //====Read in blocks from startPoint===========
    for(n=startPoint;n<num_blocks;n++){
      sprintf(blockFile,"%soccupancies/block_%d.dat",sdir,n+1);
      if((inputPtr=fopen(blockFile,"r"))==NULL){
	printf("Cannot open file: %s\n", blockFile);
	printf("No more blocks to read from!\n");
	//exit(EXIT_FAILURE);
	break;
      }
      else
	if (!(n % 100)) 
	  printf("Reading from file: %s\n", blockFile);
      i=0;
      for(i=0;i<N;i++){
	for(j=0;j<numTemps;j++)
	  fscanf(inputPtr,"%ld",&occupanciesTEMP[j][i]);      
      }
      fclose(inputPtr);
      //printf("Read in: %ld\n",occupanciesTEMP[3][200]);
         
  
      
      //==Compute the total occupancy (unnormalised average)===
      for(i=0;i<N;i++){
	for(j=0;j<numTemps;j++)
	  occupancies[j][i]+=occupanciesTEMP[j][i];
      }
      //printf("Current running total: %ld\n",occupancies[3][200]);
      
    }//loop over block files


    printf("*****************************************************************************\n\n");
  }//loop over input files
  


  

  long unsigned int totalSteps=0;
  double relOccupancies[18][1000];
  double FE[18][1000];
  double basePoint;

  for(i=0;i<N;i++)
    totalSteps += occupancies[0][i];

  printf("total steps=%ld; weightfile=%s\n",totalSteps, weightFile);


  
  int  dummyInt;

  //printf("Nmax=%d\n",N);


  //=====Read in weight file===============
  if((weightPtr=fopen(weightFile,"r"))==NULL)
    printf("Cannot open weight file: %s\n", weightFile);
  else{
    //printf("Nmax=%d\n",N);
    for(i=0;i<N;i++){
      //printf("Nmax=%d\n",N);
      fscanf(weightPtr,"%d %lf",&dummyInt, &bias[i]);
      //printf("%d %d %f %d\n",i, dummyInt, bias[i],N);
      }
  }
  fclose(weightPtr);
  printf("Weight file read\n");
  //printf("Nmax=%d\n",N);




  //===Compute the unshifted free energy========
  for(i=0;i<N;i++){
    //printf("Loop in!\n");
    for(j=0;  j<numTemps ;   j++){
      relOccupancies[j][i] = 1.0*occupancies[j][i]/(1.0*totalSteps);      
      if(relOccupancies[j][i]>0.0)
	FE[j][i] = -log(relOccupancies[j][i]/(exp(bias[i])));
	//FE[j][i] = -log(relOccupancies[j][i]);
      else
	FE[j][i] = FE[j][i-1];
      //printf("%d %d %f %f\n",j,i,relOccupancies[j][i], 	FE[j][i] );
    }
  }


  //===Find the FE at the match point and subtract=======
  for(j=0; j<=numTemps; j++){
    basePoint = FE[j][matchPoint];
    printf("matchPoint=%d baseFE=%f N=%d\n",matchPoint, basePoint, N );
    for(i=0;i<N;i++)
      FE[j][i] -= basePoint;
  }
  

  //printf("Num %d\n",numTemps);
  //printf("Number of Temps = %d\n",numTemps);
  
  FILE *occOutputPtr, *FEoutputPtr, *biasOutputPtr;
  char occOutputFile[400], FEoutputFile[400];
  for(j=0;j<numTemps;j++){

    
    /*
    sprintf(occOutputFile,"%soccW_chain%d.dat",ddir,j);
    sprintf(FEoutputFile,"%sFE_chain%d.dat",ddir,j);
    occOutputPtr = fopen(occOutputFile,"w");
    FEoutputPtr = fopen(FEoutputFile, "w");
    */

    if( j== TEMP_INTEREST){
      biasOutputPtr = fopen(argv[argc-1],"w");
      for(i=0;i<N;i++)
	fprintf(biasOutputPtr,"%d %f\n",i, FE[j][i]);
      fclose(biasOutputPtr);
    }

    /*
    for(i=0;i<N;i++){
      fprintf(occOutputPtr,"%d %f\n", i, relOccupancies[j][i]);
      fprintf(FEoutputPtr,"%d %f\n", i, FE[j][i]);
    }
    fclose(occOutputPtr);
    fclose(FEoutputPtr);
    */
  }

  printf("Finished!\n");

  return 0;
}

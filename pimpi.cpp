//**************************************************
// 
// Author: N8 Swalley
// Date: 12/7/2019
//
// This program uses MPI to approximate pi
//**************************************************

#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <iomanip>
#include "mpi.h"  // Message Passing Interface (MPI)
using namespace std;

// Do this ONCE when you start up Thomas.Butler.edu to set to a 64 bit processor
//		module load openmpi -x86_64

//  The following line is to compile your program
// 		mpicxx <yourProgram>.cpp -o a.out 

// The following line is to run your compiled program   
// 		mpirun -np 32 a.out




int main(int argc, char * argv[])
{
	int myRank;  		// My CPU number for this program
	int numCPUs;		// Number of CPUs that we have
	int sourceRank;		// Rank of the sender
	int destRank;		// Rank of destination
	int msgNum = 0;
	MPI_Status status;	// Return status for receive

	// Start MPI
	MPI_Init(&argc, &argv);
	
	// Find out my rank!
	MPI_Comm_rank(MPI_COMM_WORLD, &myRank);
	
	// Find out the number of processess!
	MPI_Comm_size(MPI_COMM_WORLD, &numCPUs);
	
	
	// -------------------- Know the problem --------------------
	double N = 0;
	double temp_pi = 0;
	double final_pi;
	int start =0;

		if (myRank == 0)
		{
			cout << "Please enter the number: ";
			cin >> N;
			for(int loopVariable2 = 1; loopVariable2 < numCPUs; loopVariable2++)
			{
			
				MPI_Send(&N, 1, MPI_DOUBLE, loopVariable2, msgNum, MPI_COMM_WORLD);
			}
		}
		else
		{
			MPI_Recv(&N, 1, MPI_DOUBLE, 0, msgNum, MPI_COMM_WORLD, &status);
		}

	
	for(int loopVariable = N - myRank; loopVariable > 0;  loopVariable-=numCPUs)
	{
		temp_pi += (double)1/(double)(pow(loopVariable, 2)) ;
	}
	
	MPI_Allreduce(&temp_pi, &final_pi, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);		
	final_pi = sqrt((double)6*final_pi);
	
	//  -------------------- Print out the final results to proccessor 0 --------------------
	if (myRank == 0)
	{
		cout << "Pi is approximately: " << fixed << setprecision(20) << final_pi << endl;
	}
	// Shut down MPI
	MPI_Finalize();
	
	return 0;
}

import java.io.*;
import java.util.Scanner;

class roundrobin {

    public static void schedule(int n, int quantum, int bt[], int wt[], int tat[]) {
        int rp = n;
        int j = 0;
        int time = 0;
        System.out.println("Process allocation to CPU during ROUND ROBIN SCHEDULING : ");
        int prt[] = bt.clone();
        while(rp > 0) {
            if(prt[j] > quantum) {
                prt[j] -= quantum;
                time += quantum;
                System.out.print("| P["+(j+1)+"] ");
            }
            else if(prt[j] <= quantum && prt[j] > 0) {
                prt[j] = 0;
                time += prt[j];
                tat[j] = time;
                System.out.print("| P["+(j+1)+"] ");
                rp--;
            }
            j = (j+1)%n;
        }
        System.out.println();

        for(int i=0; i<n; i++) {
            wt[i] = tat[i] - bt[i];
        }
    }

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);

        System.out.print("Enter the number of process : ");
        int n = in.nextInt();

        int bt[] = new int[n];
        int wt[] = new int[n];
        int tat[] = new int[n];
        int quantum;

        System.out.println("Enter the burst time of each process : ");
        for(int i=0; i<n; i++) {
            System.out.print("Process "+(i+1)+" : ");
            bt[i] = in.nextInt();
        }

        System.out.print("Enter CPU quantum : ");
        quantum = in.nextInt();

        schedule(n, quantum, bt, wt, tat);

        int avgwt = 0, avgtat = 0;
        System.out.println("Process\tBurstTime\tWaitingTime\tTurnAroundTime");
        for(int i=0; i<n; i++) {
            avgwt += wt[i];
            avgtat += tat[i];
            System.out.println((i+1)+"\t\t"+bt[i]+"\t\t"+wt[i]+"\t\t"+tat[i]);
        }

        System.out.println("Avg waiting time : "+avgwt/(double)n);
        System.out.println("Avg turnaround time : "+avgtat/(double)n);

        in.close();
    }
}
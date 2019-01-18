import java.io.*;
import java.util.Scanner;

class priority {

    public static void schedule(int n, int p[], int pri[], int bt[], int wt[], int tat[]) {
        for(int i=0; i<n-1; i++) {
            int mp = i;
            for(int j=i+1; j<n; j++) {
                if(pri[mp] < pri[j])
                    mp = j;
            }
            int temp = pri[i];
            pri[i] = pri[mp];
            pri[mp] = temp;

            temp = p[i];
            p[i] = p[mp];
            p[mp] = temp;

            temp = bt[i];
            bt[i] = bt[mp];
            bt[mp] = temp;
        }

        wt[0] = 0;
        tat[0] = wt[0] + bt[0];
        for(int i=1; i<n; i++) {
            wt[i] = tat[i-1];
            tat[i] = wt[i] + bt[i];
        }
    }

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);

        System.out.print("Enter the no. of process : ");
        int n = in.nextInt();

        int p[]= new int[n];
        int pri[]= new int[n];
        int bt[] = new int[n];
        int wt[] = new int[n];
        int tat[] = new int[n];

        System.out.println("Enter burst time for each process : ");
        for(int i=0; i<n; i++) {
            p[i] = i+1;
            System.out.print("Process "+(i+1)+" : ");
            bt[i] = in.nextInt();
        }
        System.out.println("Enter the priority for each process : ");
        for(int i=0; i<n; i++) {
            System.out.print("Priority of process "+ (i+1) + " : ");
            pri[i] = in.nextInt();
        }

        schedule(n, p, pri, bt, wt, tat);

        int avgwt = 0, avgtat = 0;
        System.out.println("After PRIORITY SCHEDULING : ");
        System.out.println("Process\tPriority\tBurstTime\tWaitingTime\tTurnaroundTime");
        for(int i=0; i<n; i++) {
            avgwt += wt[i];
            avgtat += tat[i];
            System.out.println(p[i]+"\t\t"+pri[i]+"\t\t"+bt[i]+"\t\t"+wt[i]+"\t\t"+tat[i]);
        }

        System.out.println("Avg waiting time : " + avgwt/(double)n);
        System.out.println("Avg turnaround time : " + avgtat/(double)n);

        in.close();

     }
}
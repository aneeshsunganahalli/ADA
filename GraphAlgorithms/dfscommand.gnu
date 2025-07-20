set title "DFS Graph Algorithm Analysis"
set xrange [0:50]
set yrange [0:100]
set xlabel "Number of Vertices"
set ylabel "Operations Count"
set style data linespoints
plot "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GraphAlgorithms\\DFS_ConnectedWithCycle.txt" title "Connected with Cycle", "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GraphAlgorithms\\DFS_ConnectedNoCycle.txt" title "Connected No Cycle", "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GraphAlgorithms\\DFS_Disconnected.txt" title "Disconnected"

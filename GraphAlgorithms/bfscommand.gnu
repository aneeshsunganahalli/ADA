set title "BFS Graph Algorithm Analysis"
set xrange [0:50]
set yrange [0:100]
set xlabel "Number of Vertices"
set ylabel "Operations Count"
set style data linespoints
plot "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GraphAlgorithms\\BFS_ConnectedWithCycle.txt" title "Connected with Cycle", "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GraphAlgorithms\\BFS_ConnectedNoCycle.txt" title "Connected No Cycle", "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GraphAlgorithms\\BFS_Disconnected.txt" title "Disconnected"

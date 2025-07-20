set title "Warshall's Algorithm Analysis - Transitive Closure"
set xrange [0:50]
set yrange [0:250000]
set xlabel "Number of Vertices"
set ylabel "Operations Count"
set style data linespoints
plot "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\WarshallFloyd\\Warshall_Sparse.txt" title "Sparse Graph", "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\WarshallFloyd\\Warshall_Medium.txt" title "Medium Density", "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\WarshallFloyd\\Warshall_Dense.txt" title "Dense Graph"

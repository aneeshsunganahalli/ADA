set title "DFS-based Topological Sort Analysis"
set xrange [0:50]
set yrange [0:100]
set xlabel "Number of Vertices"
set ylabel "Operations Count"
set style data linespoints
plot "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\TopologicalSort\\DFS_Linear.txt" title "Linear DAG", "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\TopologicalSort\\DFS_Tree.txt" title "Tree-like DAG", "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\TopologicalSort\\DFS_Dense.txt" title "Dense DAG"

# Second plot for Binary Search
set title "Binary Search"
set xrange [0:300]
set yrange [0:20]  # Binary search will have much fewer operations
set xlabel "Input Size"
set ylabel "Operation Count"
set style data linespoints
plot "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\Searching\\BinaryWorstCase.txt" title "Worst Case", "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\Searching\\BinaryBestCase.txt" title "Best Case"s
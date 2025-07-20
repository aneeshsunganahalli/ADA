set title "Selection Sort Analysis"
set xrange [0:1000]
set yrange [0:500000]
set xlabel "Input Size"
set ylabel "Comparisons Count"
set style data linespoints
plot "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\Sorting\\SelectionWorstCase.txt" title "Worst Case", "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\Sorting\\SelectionBestCase.txt" title "Best Case", "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\Sorting\\SelectionAvgCase.txt" title "Average Case"

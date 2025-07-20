set title "Quick Sort Analysis"
set xrange [0:1000]
set yrange [0:50000]
set xlabel "Input Size"
set ylabel "Comparisons Count"
set style data linespoints
plot "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\QuickSort\\QuickWorstCase.txt" title "Worst Case", "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\QuickSort\\QuickBestCase.txt" title "Best Case", "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\QuickSort\\QuickAvgCase.txt" title "Average Case"

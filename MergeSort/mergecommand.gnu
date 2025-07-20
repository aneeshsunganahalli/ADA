set title "Merge Sort Analysis"
set xrange [0:1000]
set yrange [0:15000]
set xlabel "Input Size"
set ylabel "Comparisons Count"
set style data linespoints
plot "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\MergeSort\\MergeWorstCase.txt" title "Worst Case", "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\MergeSort\\MergeBestCase.txt" title "Best Case", "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\MergeSort\\MergeAvgCase.txt" title "Average Case"

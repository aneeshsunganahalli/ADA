set title "Bubble Sort Analysis"
set xrange [0:1000]
set yrange [0:500000]
set xlabel "Input Size"
set ylabel "Comparisons Count"
set style data linespoints
plot "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\Sorting\\BubbleWorstCase.txt" title "Worst Case", "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\Sorting\\BubbleBestCase.txt" title "Best Case", "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\Sorting\\BubbleAvgCase.txt" title "Average Case"

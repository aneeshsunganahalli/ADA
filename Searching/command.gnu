set title "Linear Search"
set xrange [0:300]
set yrange [0:100]
set xlabel "Input Size"
set ylabel "Operation Count"
set style data linespoints
plot "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\Searching\\WorstCase.txt" title "Worst Case", "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\Searching\\BestCase.txt" title "Best Case"
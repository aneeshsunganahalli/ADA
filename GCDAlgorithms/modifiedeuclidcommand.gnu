set title "Modified Euclid's Algorithm Analysis"
set xrange [0:200]
set yrange [0:500]
set xlabel "Input Size"
set ylabel "Operations Count"
set style data linespoints
plot "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GCDAlgorithms\\ModifiedEuclid_BestCase.txt" title "Best Case", "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GCDAlgorithms\\ModifiedEuclid_AvgCase.txt" title "Average Case", "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GCDAlgorithms\\ModifiedEuclid_WorstCase.txt" title "Worst Case"

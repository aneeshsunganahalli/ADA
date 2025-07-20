set title "Euclid's Algorithm Analysis"
set xrange [0:1000]
set yrange [0:50]
set xlabel "Input Size"
set ylabel "Operations Count"
set style data linespoints
plot "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GCDAlgorithms\\Euclid_Consecutive.txt" title "Consecutive Numbers", "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GCDAlgorithms\\Euclid_RandomPairs.txt" title "Random Pairs", "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GCDAlgorithms\\Euclid_WorstCase.txt" title "Worst Case (Fibonacci)"

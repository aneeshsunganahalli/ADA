set title "Heap Sort Analysis (Bottom-up Construction)"
set xrange [0:1000]
set yrange [0:20000]
set xlabel "Input Size"
set ylabel "Comparisons Count"
set style data linespoints
plot "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\HeapSort\\HeapWorstCase.txt" title "Worst Case", "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\HeapSort\\HeapBestCase.txt" title "Best Case", "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\HeapSort\\HeapAvgCase.txt" title "Average Case"

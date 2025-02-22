#include <stdio.h>
#include <limits.h>
#include "ft_printf.h" // Include your ft_printf header

void compare_printf(const char *format, long long  i) {
    int ret_ft, ret_orig;


    printf("ft_printf:\n");
    printf("[");
    fflush(NULL);
    ret_ft = ft_printf(format, i);
    printf("]\n");
    printf("->Return value: %d\n", ret_ft);
    fflush(NULL);

    // Test original printf
    printf("printf:\n");
    printf("[");
    fflush(stdout);
    ret_orig = printf(format, i);
    printf("]\n");
    printf("->Return value: %d\n", ret_orig);
    fflush(stdout);

    // Compare return values
    if (ret_ft != ret_orig) {
        printf("⚠️ Difference in return values! ft_printf: %d, printf: %d in format: %s\n", ret_ft, ret_orig, format);
    } else {
        printf("✅ Return values match.\n");
    }

    printf("--------------------------------------------------\n");

    // Cleanup variadic arguments
}

int main() {
    printf("Comparing ft_printf with printf:\n");
    printf("--------------------------------------------------\n");

    // //Test cases for comparison
	// //compare_printf(" here : %-2147483648d", +10);
    //    compare_printf(" %03d ", 15);
	// compare_printf(" %04d ", 16);
	// compare_printf(" %05d ", 17);
	// compare_printf(" %04d ", -14);
	// compare_printf(" %05d ", -15);
	// compare_printf(" %06d ", -16);
	// compare_printf(" %011d ", LONG_MAX);
	// compare_printf(" %012d ", LONG_MIN);
	// compare_printf(" %013d ", UINT_MAX);
	// compare_printf(" %014d ", ULONG_MAX);
	// compare_printf(" %015d ", 9223372036854775807LL);
	// compare_printf(" %09d ", INT_MAX);
	// compare_printf(" %03i ", 1);
 	// compare_printf(" %04i ", 9);
 	// compare_printf(" %03i ", 15);
 	// compare_printf(" %04i ", 16);
 	// compare_printf(" %05i ", 17);
 	// compare_printf(" %05i ", -15);
 	// compare_printf(" %-4d ", -14);
 	// compare_printf(" %-5d ", -15);
 	// compare_printf(" %-6d ", -16);
 	// compare_printf(" %-11d ", LONG_MAX);
 	// compare_printf(" %-13d ", UINT_MAX);
 	// compare_printf(" %-14d ", ULONG_MAX);
 	// compare_printf(" %-15d ", 9223372036854775807LL);
 	// compare_printf(" %-9d ", INT_MAX);
 	// compare_printf(" %-5i ", -15);
 	// compare_printf(" %-6i ", -16);
 	// compare_printf(" %04d ", 9);
 	// compare_printf(" %03d ", 15);
 	// compare_printf(" %04d ", 16);
 	// compare_printf(" %05d ", 17);
 	// compare_printf(" %04d ", -14);
 	// compare_printf(" %05d ", -15);
 	// compare_printf(" %06d ", -16);
 	// compare_printf(" %011d ", LONG_MAX);
 	// compare_printf(" %012d ", LONG_MIN);
 	// compare_printf(" %013d ", UINT_MAX);
 	// compare_printf(" %014d ", ULONG_MAX);
 	// compare_printf(" %015d ", 9223372036854775807LL);
 	// //compare_printf(" %09d %010d %011d %012d %013d %014d %015d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
 	// compare_printf(" %03i ", 1);
 	// compare_printf(" %04i ", 9);
 	// compare_printf(" %03i ", 15);
 	// compare_printf(" %04i ", 16);
 	// compare_printf(" %05i ", 17);
 	// compare_printf(" %05i ", -15);
 	// compare_printf("%.2d ", -1);
 	// compare_printf("%.2d ", 1);
 	// compare_printf("%.1d ", 9);
	// compare_printf(" %03d ", 15);
	// compare_printf(" %04d ", 16);
	// compare_printf(" %05d ", 17);
	// compare_printf(" %04d ", -14);
	// compare_printf(" %05d ", -15);
	// compare_printf(" %06d ", -16);
	// compare_printf(" %011d ", LONG_MAX);
	// compare_printf(" %012d ", LONG_MIN);
	// compare_printf(" %013d ", UINT_MAX);
	// compare_printf(" %014d ", ULONG_MAX);
	// compare_printf(" %015d ", 9223372036854775807LL);
	// compare_printf(" %09d ", INT_MAX);
	// compare_printf(" %03i ", 1);
 	// compare_printf(" %04i ", 9);
 	// compare_printf(" %03i ", 15);
 	// compare_printf(" %04i ", 16);
 	// compare_printf(" %05i ", 17);
 	// compare_printf(" %05i ", -15);
 	// compare_printf(" %-4d ", -14);
 	// compare_printf(" %-5d ", -15);
 	// compare_printf(" %-6d ", -16);
 	// compare_printf(" %-11d ", LONG_MAX);
 	// compare_printf(" %-13d ", UINT_MAX);
 	// compare_printf(" %-14d ", ULONG_MAX);
 	// compare_printf(" %-15d ", 9223372036854775807LL);
 	// compare_printf(" %-9d ", INT_MAX);
 	// compare_printf(" %-5i ", -15);
 	// compare_printf(" %-6i ", -16);
 	// compare_printf(" %04d ", 9);
 	// compare_printf(" %03d ", 15);
 	// compare_printf(" %04d ", 16);
 	// compare_printf(" %05d ", 17);
 	// compare_printf(" %04d ", -14);
 	// compare_printf(" %05d ", -15);
 	// compare_printf(" %06d ", -16);
 	// compare_printf(" %011d ", LONG_MAX);
 	// compare_printf(" %012d ", LONG_MIN);
 	// compare_printf(" %013d ", UINT_MAX);
 	// compare_printf(" %014d ", ULONG_MAX);
 	// compare_printf(" %015d ", 9223372036854775807LL);
 	// //compare_printf(" %09d %010d %011d %012d %013d %014d %015d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
 	// compare_printf(" %03i ", 1);
 	// compare_printf(" %04i ", 9);
 	// compare_printf(" %03i ", 15);
 	// compare_printf(" %04i ", 16);
 	// compare_printf(" %05i ", 17);
 	// compare_printf(" %05i ", -15);
 	// compare_printf("%.2d ", -1);
 	// compare_printf("%.2d ", 1);
 	// compare_printf("%.1d ", 9);
 	// compare_printf("%.2d ", 10);
 	// compare_printf("%.3d ", 11);
 	// compare_printf("%.4d ", 15);
 	// compare_printf("%.5d ", 16);
 	// compare_printf("%.6d ", 17);
 	// compare_printf("%.1d ", 99);
 	// compare_printf(" %.2d ", -1);
 	// compare_printf(" %.3d ", -11);
 	// compare_printf(" %.4d ", -14);
 	// compare_printf(" %.3d ", -99);
 	// compare_printf(" %.4d ", -101);
 	// compare_printf(" %.10d ", LONG_MAX);
 	// compare_printf(" %.12d ", UINT_MAX);
 	// compare_printf(" %.13d ", ULONG_MAX);
 	// compare_printf(" %.14d ", 9223372036854775807LL);
 	// //compare_printf(" %.8d %.9d %.10d %.11d %.12d %.13d %.14d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
 	// compare_printf(" %.2i ", -1);
 	// compare_printf(" %.3i ", -11);
 	// compare_printf(" %.4i ", -14);
 	// compare_printf(" %.3i ", -99);
 	// compare_printf(" %.4i ", -101);
 	// compare_printf(" %.10i ", LONG_MAX);
 	// compare_printf(" %.12i ", UINT_MAX);
 	// compare_printf(" %.13i ", ULONG_MAX);
 	// compare_printf(" %.14i ", 9223372036854775807LL);
 	// compare_printf(" % d ", 0);
 	// compare_printf(" % d ", 1);
 	// compare_printf(" % d ", 9);
 	// compare_printf(" % d ", 10);
 	// compare_printf(" % d ", 11);
 	// compare_printf(" % d ", 15);
 	// compare_printf(" % d ", 16);
 	// compare_printf(" % d ", 17);
 	// compare_printf(" % d ", 99);
 	// compare_printf(" % d ", 100);
 	// compare_printf(" % d ", 101);
 	// compare_printf(" % d ", INT_MAX);
 	// compare_printf(" % d ", LONG_MIN);
 	// //compare_printf(" % d % d % d % d % d % d % d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
 	// compare_printf(" % i ", 0);
 	// compare_printf(" % i ", 1);
 	// compare_printf(" % i ", 9);
 	// compare_printf(" % i ", 10);
 	// compare_printf(" % i ", 11);
 	// compare_printf("%8.5i", 34);
 	// compare_printf("%10.5i", -216);
 	// compare_printf("%8.5i", 0);
 	// compare_printf("%8.3i", 8375);
 	// compare_printf("%8.3i", -8473);
 	// compare_printf("%-8.5i", 34);
 	// compare_printf("%-10.5i", -216);
 	// compare_printf("%-8.5i", 0);
 	// compare_printf("%-8.3i", -8473);
 	// compare_printf("%08.5i", 34);
 	// compare_printf("%010.5i", -216);
 	// compare_printf("%08.5i", 0);
 	// compare_printf("%08.3i", 8375);
 	// compare_printf("%08.3i", -8473);
 	// compare_printf("%.0i", 0);
 	// compare_printf("%.i", 0);
 	// compare_printf("%5.0i", 1);
 	// compare_printf("%5.i", 0);
 	// compare_printf("%-5.0i", 0);
 	// compare_printf("%-5.i", 0);
 	// compare_printf(" %04d ", -14);
 	// compare_printf(" %05d ", -15);
 	// compare_printf(" %06d ", -16);
 	// compare_printf(" %011d ", LONG_MAX);
 	// compare_printf(" %013d ", UINT_MAX);
 	// compare_printf(" %014d ", ULONG_MAX);
 	// compare_printf(" %015d ", 9223372036854775807LL);
 	// //compare_printf(" %09d %010d %011d %012d %013d %014d %015d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
 	// compare_printf(" %05i ", -15);
 	// compare_printf(" %06i ", -16);
 	// compare_printf(" %012i ", LONG_MIN);
	// compare_printf(" %03d ", 15);
	// compare_printf(" %04d ", 16);
	// compare_printf(" %05d ", 17);
	// compare_printf(" %04d ", -14);
	// compare_printf(" %05d ", -15);
	// compare_printf(" %06d ", -16);
	// compare_printf(" %011d ", LONG_MAX);
	// compare_printf(" %012d ", LONG_MIN);
	// compare_printf(" %013d ", UINT_MAX);
	// compare_printf(" %014d ", ULONG_MAX);
	// compare_printf(" %015d ", 9223372036854775807LL);
	// compare_printf(" %09d ", INT_MAX);
	// compare_printf(" %03i ", 1);
 	// compare_printf(" %04i ", 9);
 	// compare_printf(" %03i ", 15);
 	// compare_printf(" %04i ", 16);
 	// compare_printf(" %05i ", 17);
 	// compare_printf(" %05i ", -15);
 	// compare_printf(" %-4d ", -14);
 	// compare_printf(" %-5d ", -15);
 	// compare_printf(" %-6d ", -16);
 	// compare_printf(" %-11d ", LONG_MAX);
 	// compare_printf(" %-13d ", UINT_MAX);
 	// compare_printf(" %-14d ", ULONG_MAX);
 	// compare_printf(" %-15d ", 9223372036854775807LL);
 	// compare_printf(" %-9d ", INT_MAX);
 	// compare_printf(" %-5i ", -15);
 	// compare_printf(" %-6i ", -16);
 	// compare_printf(" %04d ", 9);
 	// compare_printf(" %03d ", 15);
 	// compare_printf(" %04d ", 16);
 	// compare_printf(" %05d ", 17);
 	// compare_printf(" %04d ", -14);
 	// compare_printf(" %05d ", -15);
 	// compare_printf(" %06d ", -16);
 	// compare_printf(" %011d ", LONG_MAX);
 	// compare_printf(" %012d ", LONG_MIN);
 	// compare_printf(" %013d ", UINT_MAX);
 	// compare_printf(" %014d ", ULONG_MAX);
 	// compare_printf(" %015d ", 9223372036854775807LL);
 	// //compare_printf(" %09d %010d %011d %012d %013d %014d %015d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
 	// compare_printf(" %03i ", 1);
 	// compare_printf(" %04i ", 9);
 	// compare_printf(" %03i ", 15);
 	// compare_printf(" %04i ", 16);
 	// compare_printf(" %05i ", 17);
 	// compare_printf(" %05i ", -15);
 	// compare_printf("%.2d ", -1);
 	// compare_printf("%.2d ", 1);
 	// compare_printf("%.1d ", 9);
 	// compare_printf("%.2d ", 10);
 	// compare_printf("%.3d ", 11);
 	// compare_printf("%.4d ", 15);
 	// compare_printf("%.5d ", 16);
 	// compare_printf("%.6d ", 17);
 	// compare_printf("%.1d ", 99);
	// compare_printf(" %03d ", 15);
	// compare_printf(" %04d ", 16);
	// compare_printf(" %05d ", 17);
	// compare_printf(" %04d ", -14);
	// compare_printf(" %05d ", -15);
	// compare_printf(" %06d ", -16);
	// compare_printf(" %011d ", LONG_MAX);
	// compare_printf(" %012d ", LONG_MIN);
	// compare_printf(" %013d ", UINT_MAX);
	// compare_printf(" %014d ", ULONG_MAX);
	// compare_printf(" %015d ", 9223372036854775807LL);
	// compare_printf(" %09d ", INT_MAX);
	// compare_printf(" %03i ", 1);
 	// compare_printf(" %04i ", 9);
 	// compare_printf(" %03i ", 15);
 	// compare_printf(" %04i ", 16);
 	// compare_printf(" %05i ", 17);
 	// compare_printf(" %05i ", -15);
 	// compare_printf(" %-4d ", -14);
 	// compare_printf(" %-5d ", -15);
 	// compare_printf(" %-6d ", -16);
 	// compare_printf(" %-11d ", LONG_MAX);
 	// compare_printf(" %-13d ", UINT_MAX);
 	// compare_printf(" %-14d ", ULONG_MAX);
 	// compare_printf(" %-15d ", 9223372036854775807LL);
 	// compare_printf(" %-9d ", INT_MAX);
 	// compare_printf(" %-5i ", -15);
 	// compare_printf(" %-6i ", -16);
 	// compare_printf(" %04d ", 9);
 	// compare_printf(" %03d ", 15);
 	// compare_printf(" %04d ", 16);
 	// compare_printf(" %05d ", 17);
 	// compare_printf(" %04d ", -14);
 	// compare_printf(" %05d ", -15);
 	// compare_printf(" %06d ", -16);
 	// compare_printf(" %011d ", LONG_MAX);
 	// compare_printf(" %012d ", LONG_MIN);
 	// compare_printf(" %013d ", UINT_MAX);
 	// compare_printf(" %014d ", ULONG_MAX);
 	// compare_printf(" %015d ", 9223372036854775807LL);
 	// //compare_printf(" %09d %010d %011d %012d %013d %014d %015d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
 	// compare_printf(" %03i ", 1);
 	// compare_printf(" %04i ", 9);
 	// compare_printf(" %03i ", 15);
 	// compare_printf(" %04i ", 16);
 	// compare_printf(" %05i ", 17);
 	// compare_printf(" %05i ", -15);
 	// compare_printf("%.2d ", -1);
 	// compare_printf("%.2d ", 1);
 	// compare_printf("%.1d ", 9);
 	// compare_printf("%.2d ", 10);
 	// compare_printf("%.3d ", 11);
 	// compare_printf("%.4d ", 15);
 	// compare_printf("%.5d ", 16);
 	// compare_printf("%.6d ", 17);
 	// compare_printf("%.1d ", 99);
 	// compare_printf(" %.2d ", -1);
 	// compare_printf(" %.3d ", -11);
 	// compare_printf(" %.4d ", -14);
 	// compare_printf(" %.3d ", -99);
 	// compare_printf(" %.4d ", -101);
 	// compare_printf(" %.10d ", LONG_MAX);
 	// compare_printf(" %.12d ", UINT_MAX);
 	// compare_printf(" %.13d ", ULONG_MAX);
 	// compare_printf(" %.14d ", 9223372036854775807LL);
 	// //compare_printf(" %.8d %.9d %.10d %.11d %.12d %.13d %.14d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
 	// compare_printf(" %.2i ", -1);
 	// compare_printf(" %.3i ", -11);
 	// compare_printf(" %.4i ", -14);
 	// compare_printf(" %.3i ", -99);
 	// compare_printf(" %.4i ", -101);
 	// compare_printf(" %.10i ", LONG_MAX);
 	// compare_printf(" %.12i ", UINT_MAX);
 	// compare_printf(" %.13i ", ULONG_MAX);
 	// compare_printf(" %.14i ", 9223372036854775807LL);
 	// compare_printf(" % d ", 0);
 	// compare_printf(" % d ", 1);
 	// compare_printf(" % d ", 9);
 	// compare_printf(" % d ", 10);
 	// compare_printf(" % d ", 11);
 	// compare_printf(" % d ", 15);
 	// compare_printf(" % d ", 16);
 	// compare_printf(" % d ", 17);
 	// compare_printf(" % d ", 99);
 	// compare_printf(" % d ", 100);
 	// compare_printf(" % d ", 101);
 	// compare_printf(" % d ", INT_MAX);
 	// compare_printf(" % d ", LONG_MIN);
 	// //compare_printf(" % d % d % d % d % d % d % d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
 	// compare_printf(" % i ", 0);
 	// compare_printf(" % i ", 1);
 	// compare_printf(" % i ", 9);
 	// compare_printf(" % i ", 10);
 	// compare_printf(" % i ", 11);
 	// compare_printf("%8.5i", 34);
 	// compare_printf("%10.5i", -216);
 	// compare_printf("%8.5i", 0);
 	/test_spdxiucpercent: 6/8 correct functions | bonus_one: 3/3 correct functions | bonus_two: 3/3 correct functions
/ compare_printf("%8.3i", 8375);
 	// compare_printf("%8.3i", -8473);
 	// compare_printf("%-8.5i", 34);
 	// compare_printf("%-10.5i", -216);
 	// compare_printf("%-8.5i", 0);
 	// compare_printf("%-8.3i", -8473);
 	// compare_printf("%08.5i", 34);
 	// compare_printf("%010.5i", -216);
 	// compare_printf("%08.5i", 0);
 	// compare_printf("%08.3i", 8375);
 	// compare_printf("%08.3i", -8473);
 	// compare_printf("%.0i", 0);
 	// compare_printf("%.i", 0);
 	// compare_printf("%5.0i", 1);
 	// compare_printf("%5.i", 0);
 	// compare_printf("%-5.0i", 0);
 	// compare_printf("%-5.i", 0);
 	// compare_printf(" %04d ", -14);
 	// compare_printf(" %05d ", -15);
 	// compare_printf(" %06d ", -16);
 	// compare_printf(" %011d ", LONG_MAX);
 	// compare_printf(" %013d ", UINT_MAX);
 	// compare_printf(" %014d ", ULONG_MAX);
 	// compare_printf(" %015d ", 9223372036854775807LL);
 	// //compare_printf(" %09d %010d %011d %012d %013d %014d %015d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
 	// compare_printf(" %05i ", -15);
 	// compare_printf(" %06i ", -16);
 	// compare_printf(" %012i ", LONG_MIN);
 	// compare_printf(" %01i ", -99);
 	// compare_printf(" %014i ", ULONG_MAX);
 	// compare_printf(" %015i ", 9223372036854775807LL);
 	// //compare_printf(" %09i %010i %011i %012i %013i %014i %015i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
 	// compare_printf(" %+d ", 0);
 	// compare_printf(" %+d ", 9);
 	// compare_printf(" %+d ", 10);
 	// compare_printf(" %+d ", 11);
 	// compare_printf(" %+d ", 15);
 	// compare_printf(" %+d ", 16);
 	// compare_printf(" %+d ", 17);
 	// compare_printf(" %+d ", 99);
 	// compare_printf(" %+d ", 100);
 	// compare_printf(" %+d ", 101);
 	// compare_printf(" %+d ", INT_MAX);
 	// compare_printf(" %+d ", LONG_MIN);
 	// //compare_printf(" %+d %+d %+d %+d %+d %+d %+d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
 	// compare_printf(" %+i ", 0);
 	// compare_printf(" %+i ", 1);
 	// compare_printf(" %+i ", 9);
 	// compare_printf(" %+i ", 10);
 	// compare_printf(" %+i ", 11);
 	// compare_printf(" %+i ", 15);
 	// compare_printf("%+48.27d", -61180352);
 	// compare_printf("\\!/%+8d\\!/", 0);
 	// compare_printf("42%+60d42", 2034180068);
 	// compare_printf("\\!/%+11d\\!/", 1884143904);
	// compare_printf("\\!/% -12.8d\\!/", 0);
	// compare_printf("\\!/% -38.2d\\!/", 463383700);
	// compare_printf("\\!/%+-55.33d\\!/", 0);
	// compare_printf("^.^/%+-24.2d^.^/", 0);
	// compare_printf("\\!/%+-34.8d\\!/", 0);
 	// compare_printf(" %.2d ", -1);
 	// compare_printf(" %.3d ", -11);
 	// compare_printf(" %.4d ", -14);
 	// compare_printf(" %.3d ", -99);
 	// compare_printf(" %.4d ", -101);
 	// compare_printf(" %.10d ", LONG_MAX);
 	// compare_printf(" %.12d ", UINT_MAX);
 	// compare_printf(" %.13d ", ULONG_MAX);
 	// compare_printf(" %.14d ", 9223372036854775807LL);
 	// //compare_printf(" %.8d %.9d %.10d %.11d %.12d %.13d %.14d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
 	// compare_printf(" %.2i ", -1);
 	// compare_printf(" %.3i ", -11);
 	// compare_printf(" %.4i ", -14);
 	// compare_printf(" %.3i ", -99);
 	// compare_printf(" %.4i ", -101);
 	// compare_printf(" %.10i ", LONG_MAX);
 	// compare_printf(" %.12i ", UINT_MAX);
 	// compare_printf(" %.13i ", ULONG_MAX);
 	// compare_printf(" %.14i ", 9223372036854775807LL);
 	// compare_printf(" % d ", 0);
 	// compare_printf(" % d ", 1);
 	// compare_printf(" % d ", 9);
 	// compare_printf(" % d ", 10);
 	// compare_printf(" % d ", 11);
 	// compare_printf(" % d ", 15);
 	// compare_printf(" % d ", 16);
 	// compare_printf(" % d ", 17);
 	// compare_printf(" % d ", 99);
 	// compare_printf(" % d ", 100);
 	// compare_printf(" % d ", 101);
 	// compare_printf(" % d ", INT_MAX);
 	// compare_printf(" % d ", LONG_MIN);
 	// //compare_printf(" % d % d % d % d % d % d % d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
 	// compare_printf(" % i ", 0);
 	// compare_printf(" % i ", 1);
 	// compare_printf(" % i ", 9);
 	// compare_printf(" % i ", 10);
 	// compare_printf(" % i ", 11);
 	// compare_printf("%8.5i", 34);
 	// compare_printf("%10.5i", -216);
 	// compare_printf("%8.5i", 0);
 	// compare_printf("%8.3i", 8375);
 	// compare_printf("%8.3i", -8473);
 	// compare_printf("%-8.5i", 34);
 	// compare_printf("%-10.5i", -216);
 	// compare_printf("%-8.5i", 0);
 	// compare_printf("%-8.3i", -8473);
 	// compare_printf("%08.5i", 34);
 	// compare_printf("%010.5i", -216);
 	// compare_printf("%08.5i", 0);
 	// compare_printf("%08.3i", 8375);
 	// compare_printf("%08.3i", -8473);
 	// compare_printf("%.0i", 0);
 	// compare_printf("%.i", 0);
 	// compare_printf("%5.0i", 1);
 	// compare_printf("%5.i", 0);
 	// compare_printf("%-5.0i", 0);
 	// compare_printf("%-5.i", 0);
 	// compare_printf(" %04d ", -14);
 	// compare_printf(" %05d ", -15);
 	// compare_printf(" %06d ", -16);
 	// compare_printf(" %011d ", LONG_MAX);
 	// compare_printf(" %013d ", UINT_MAX);
 	// compare_printf(" %014d ", ULONG_MAX);
 	// compare_printf(" %015d ", 9223372036854775807LL);
 	// //compare_printf(" %09d %010d %011d %012d %013d %014d %015d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
 	// compare_printf(" %05i ", -15);
 	// compare_printf(" %06i ", -16);
 	// compare_printf(" %+d ", 11);
 	// compare_printf(" %+d ", 15);
 	// compare_printf(" %+d ", 16);
 	// compare_printf(" %+d ", 17);
 	// compare_printf(" %+d ", 99);
 	// compare_printf(" %+d ", 100);
 	// compare_printf(" %+d ", 101);
 	// compare_printf(" %+d ", INT_MAX);
 	// compare_printf(" %+d ", LONG_MIN);
 	// //compare_printf(" %+d %+d %+d %+d %+d %+d %+d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
 	// compare_printf(" %+i ", 0);
 	// compare_printf(" %+i ", 1);
 	// compare_printf(" %+i ", 9);
 	// compare_printf(" %+i ", 10);
 	// compare_printf(" %+i ", 11);
 	// compare_printf(" %+i ", 15);
 	// compare_printf("%+48.27d", -61180352);
 	// compare_printf("\\!/%+8d\\!/", 0);
 	// compare_printf("42%+60d42", 2034180068);
 	// compare_printf("\\!/%+11d\\!/", 1884143904);
	// compare_printf("\\!/% -12.8d\\!/", 0);
	// compare_printf("\\!/% -38.2d\\!/", 463383700);
	// compare_printf("\\!/%+-55.33d\\!/", 0);
	// compare_printf("^.^/%+-24.2d^.^/", 0);
	// compare_printf("\\!/%+-34.8d\\!/", 0);
 	// compare_printf(" %014i ", ULONG_MAX);
 	// compare_printf(" %015i ", 9223372036854775807LL);
 	// //compare_printf(" %09i %010i %011i %012i %013i %014i %015i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
 	// compare_printf(" %+d ", 0);
 	// compare_printf(" %+d ", 9);
 	// compare_printf(" %+d ", 10);
 	// compare_printf(" %+d ", 11);
 	// compare_printf(" %+d ", 15);
 	// compare_printf(" %+d ", 16);
 	// compare_printf(" %+d ", 17);
 	// compare_printf(" %+d ", 99);
 	// compare_printf(" %+d ", 100);
 	// compare_printf(" %+d ", 101);
 	// compare_printf(" %+d ", INT_MAX);
 	// compare_printf(" %+d ", LONG_MIN);
 	// //compare_printf(" %+d %+d %+d %+d %+d %+d %+d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
 	// compare_printf(" %+i ", 0);
 	// compare_printf(" %+i ", 1);
 	// compare_printf(" %+i ", 9);
 	// compare_printf(" %+i ", 10);
 	// compare_printf(" %+i ", 11);
 	// compare_printf(" %+i ", 15);
 	// compare_printf("%+48.27d", -61180352);
 	// compare_printf("\\!/%+8d\\!/", 0);
 	// compare_printf("42%+60d42", 2034180068);
 	// compare_printf("\\!/%+11d\\!/", 1884143904);
	// compare_printf("\\!/% -12.8d\\!/", 0);
	// compare_printf("\\!/% -38.2d\\!/", 463383700);
	// compare_printf("\\!/%+-55.33d\\!/", 0);
	// compare_printf("^.^/%+-24.2d^.^/", 0);
	// compare_printf("\\!/%+-34.8d\\!/", 0);
 	// compare_printf("%.3d ", 11);
 	// compare_printf("%.4d ", 15);
 	// compare_printf("%.5d ", 16);
 	// compare_printf("%.6d ", 17);
 	// compare_printf("%.1d ", 99);
 	// compare_printf(" %.2d ", -1);
 	// compare_printf(" %.3d ", -11);
 	// compare_printf(" %.4d ", -14);
 	// compare_printf(" %.3d ", -99);
 	// compare_printf(" %.4d ", -101);
 	// compare_printf(" %.10d ", LONG_MAX);
 	// compare_printf(" %.12d ", UINT_MAX);
 	// compare_printf(" %.13d ", ULONG_MAX);
 	// compare_printf(" %.14d ", 9223372036854775807LL);
 	// //compare_printf(" %.8d %.9d %.10d %.11d %.12d %.13d %.14d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
 	// compare_printf(" %.2i ", -1);
 	// compare_printf(" %.3i ", -11);
 	// compare_printf(" %.4i ", -14);
 	// compare_printf(" %.3i ", -99);
 	// compare_printf(" %.4i ", -101);
 	// compare_printf(" %.10i ", LONG_MAX);
 	// compare_printf(" %.12i ", UINT_MAX);
 	// compare_printf(" %.13i ", ULONG_MAX);
		// compare_printf(" %.14i ", 9223372036854775807LL);
 	// compare_printf(" % d ", 0);
 	// compare_printf(" % d ", 1);
 	// compare_printf(" % d ", 9);
 	// compare_printf(" % d ", 10);
 	// compare_printf(" % d ", 11);
 	// compare_printf(" % d ", 15);
 	// compare_printf(" % d ", 16);
 	// compare_printf(" % d ", 17);
 	// compare_printf(" % d ", 99);
 	// compare_printf(" % d ", 100);
 	// compare_printf(" % d ", 101);
 	// compare_printf(" % d ", INT_MAX);
 	// compare_printf(" % d ", LONG_MIN);
 	// //compare_printf(" % d % d % d % d % d % d % d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
 	// compare_printf(" % i ", 0);
 	// compare_printf(" % i ", 1);
 	// compare_printf(" % i ", 9);
 	// compare_printf(" % i ", 10);
 	// compare_printf(" % i ", 11);
 	// compare_printf("%8.5i", 34);
 	// compare_printf("%10.5i", -216);
 	// compare_printf("%8.5i", 0);
 	// compare_printf("%8.3i", 8375);
 	// compare_printf("%8.3i", -8473);
 	// compare_printf("%-8.5i", 34);
 	// compare_printf("%-10.5i", -216);
 	// compare_printf("%-8.5i", 0);
 	// compare_printf("%-8.3i", -8473);
 	// compare_printf("%08.5i", 34);
 	// compare_printf("%010.5i", -216);
 	// compare_printf("%08.5i", 0);
 	// compare_printf("%08.3i", 8375);
 	// compare_printf("%08.3i", -8473);
 	// compare_printf("%.0i", 0);
 	// compare_printf("%.i", 0);
 	// compare_printf("%5.0i", 1);
 	// compare_printf("%5.i", 0);
 	// compare_printf("%-5.0i", 0);
 	// compare_printf("%-5.i", 0);
 	// compare_printf(" %04d ", -14);
 	// compare_printf(" %05d ", -15);
 	// compare_printf(" %06d ", -16);
 	// compare_printf(" %011d ", LONG_MAX);
 	// compare_printf(" %013d ", UINT_MAX);
 	// compare_printf(" %014d ", ULONG_MAX);
 	// compare_printf(" %015d ", 9223372036854775807LL);
 	// //compare_printf(" %09d %010d %011d %012d %013d %014d %015d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
 	// compare_printf(" %05i ", -15);
 	// compare_printf(" %06i ", -16);
 	// compare_printf(" %012i ", LONG_MIN);
 	// compare_printf(" %01i ", -99);
 	// compare_printf(" %014i ", ULONG_MAX);
 	// compare_printf(" %015i ", 9223372036854775807LL);
 	// //compare_printf(" %09i %010i %011i %012i %013i %014i %015i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
 	// compare_printf(" %+d ", 0);
 	// compare_printf(" %+d ", 9);
 	// compare_printf(" %+d ", 10);
 	// compare_printf(" %+d ", 11);
 	// compare_printf(" %+d ", 15);
 	// compare_printf(" %+d ", 16);
 	// compare_printf(" %+d ", 17);
 	// compare_printf(" %+d ", 99);
 	// compare_printf(" %+d ", 100);
 	// compare_printf(" %+d ", 101);
 	// compare_printf(" %+d ", INT_MAX);
 	// compare_printf(" %+d ", LONG_MIN);
 	// //compare_printf(" %+d %+d %+d %+d %+d %+d %+d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
 	// compare_printf(" %+i ", 0);
 	// compare_printf(" %+i ", 1);
 	// compare_printf(" %+i ", 9);
 	// compare_printf(" %+i ", 10);
 	// compare_printf(" %+i ", 11);
 	// compare_printf(" %+i ", 15);
 	// compare_printf("%+48.27d", -61180352);
 	// compare_printf("\\!/%+8d\\!/", 0);
 	// compare_printf("42%+60d42", 2034180068);
 	// compare_printf("\\!/%+11d\\!/", 1884143904);
	// compare_printf("\\!/% -12.8d\\!/", 0);
	// compare_printf("\\!/% -38.2d\\!/", 463383700);
	// compare_printf("\\!/%+-55.33d\\!/", 0);
	// compare_printf("^.^/%+-24.2d^.^/", 0);
	// compare_printf("\\!/%+-34.8d\\!/", 0);

	// printf("-----------------------------------------------------------------------------------------------------------\n");
	// compare_printf("this %i number", 0);
	// compare_printf("%i", 0);
	// compare_printf("this %d number", 0);
	// compare_printf("%3i", 0);
	// compare_printf("%-3i", 0);
	// compare_printf("%.3i", 0);
	// compare_printf("%03i", 0);
	// compare_printf("%8.5i", 0);
	// compare_printf("%-8.5i", 0);
	// compare_printf("%08.5i", 0);
	// compare_printf("%d", 0);
	// compare_printf("%3d", 0);
	// compare_printf("%-3d", 0);
	// compare_printf("%.3d", 0);
	// compare_printf("%03d", 0);
	// compare_printf("%8.5d", 0);
	// compare_printf("%-8.5d", 0);
	// compare_printf("%08.5d", 0);
	// //TEST THE %c spicifier 
	// compare_printf("%c", 'a');          // Single character
	// compare_printf("%5c", 'a');         // Width 5
	// compare_printf("%-5c", 'a');        // Left-aligned, width 5
	// compare_printf("%05c", 'a');        // Zero-padded, width 5
	// compare_printf("%5.3c", 'a');       // Width 5, precision 3 (has no effect on %c)
	// compare_printf("%-5.3c", 'a');      // Left-aligned, width 5, precision 3 (has no effect on %c)
	// compare_printf("%8c", 'a');         // Width 8
	// compare_printf("%-8c", 'a');        // Left-aligned, width 8
	// compare_printf("%08c", 'a');        // Zero-padded, width 8
	// compare_printf("%8.3c", 'a');       // Width 8, precision 3 (has no effect on %c)
	// compare_printf("%-8.3c", 'a');      // Left-aligned, width 8, precision 3 (has no effect on %c)
	//---------------------------------------------------------------------------------------------------------------------------- 
	/*compare_printf("%-7s", "hello"); // Expected: "hello  "
	compare_printf("%7s", "world");  // Expected: "  world"
	compare_printf("%.9s", "NULL");  // Expected: "NULL"
	compare_printf("%.3s", "hello"); // Expected:*/ 
	/*compare_printf("%-10s", "test"); // Expected: "test      "
	compare_printf("%10s", "test");  // Expected: "      test"
	compare_printf("%5.3s", "example"); // Expected: "  exa"
	compare_printf("%-.5s", "limit"); // Expected: "limit"
	compare_printf("%.3s", NULL);    // Expected: "(null)"
	compare_printf("%7s", NULL);     // Expected: "  (null)"
	compare_printf("%-7s", NULL);    // Expected: "(null)  "*/
	//------------------------------------------------------------------------------------------------------------------------------
	// compare_printf("%x", LONG_MAX);
	// compare_printf("%x", ULONG_MAX);
	// compare_printf("%x", 9223372036854775807LL);
	// compare_printf("%x", INT_MAX);
	// compare_printf("%x", INT_MIN);
	// //
	// compare_printf("%-1x ", 0);
	// compare_printf("%-4x ", 9);
	// compare_printf("%-1x ", 10);
	// compare_printf("%-3x ", 15);
	// compare_printf("%-4x ", 16);
	// compare_printf("%-5x ", 17);
	// compare_printf("%-1x ", 99);
	/*compare_printf("%-1x ", -9);
	compare_printf("%-10x ", INT_MIN);
	compare_printf("%-11x ", LONG_MAX);
	compare_printf("%-12x ", LONG_MIN);
	compare_printf("%-13x ", UINT_MAX);
	compare_printf("%-14x ", ULONG_MAX);
	compare_printf("%-15x ", 9223372036854775807LL);

	compare_printf("%-9x ", INT_MAX);
	compare_printf("%-10x ", INT_MIN);
	compare_printf("%-11x ", LONG_MAX);
	compare_printf("%-12x ", LONG_MIN);
	compare_printf("%-13x ", ULONG_MAX);
	compare_printf("%-14x ", 0);
	compare_printf("%-15x ", -42);

	compare_printf("%X ", LONG_MAX);
	compare_printf("%X ", LONG_MIN);
	compare_printf("%X ", ULONG_MAX);
	compare_printf("%X ", 9223372036854775807LL);
	compare_printf("%8.5x", 34);
	compare_printf("%8.5x", 0);
	compare_printf("%-8.5x", 34);
	compare_printf("%-8.5x", 0);
	compare_printf("%08.5x", 34);
	compare_printf("%08.5x", 0);
	compare_printf("%5.0x", 0);
	compare_printf("%5.x", 0);
	compare_printf("%-5.0x", 0);
	compare_printf("%-5.x", 0);
	compare_printf("%8.5x", 34);
	compare_printf("%8.5x", 0);
	compare_printf("%-8.5x", 34);
	compare_printf("%-8.5x", 0);
	compare_printf("%08.5x", 34);
	compare_printf("%08.5x", 0);
	compare_printf("%5.0x", 0);
	compare_printf("%5.x", 0);
	compare_printf("%-5.0x", 0);
	compare_printf("%-5.x", 0);

	compare_printf("%X ", INT_MAX);
	compare_printf("%X ", INT_MIN);
	compare_printf("%X ", LONG_MAX);
	compare_printf("%X ", LONG_MIN);
	compare_printf("%X ", ULONG_MAX);
	compare_printf("%X ", 0);
	compare_printf("%X ", -42);
	compare_printf("%#x ", 0);
	compare_printf("%#x ", LONG_MIN);
	compare_printf("%#x ", INT_MAX);
	compare_printf("%#x ", INT_MIN);
	compare_printf("%#x ", LONG_MAX);
	compare_printf("%#x ", LONG_MIN);
	compare_printf("%#x ", ULONG_MAX);
	compare_printf("%#x ", 0);
	compare_printf("%#x ", -42);

	compare_printf("%#X ", 0);
	compare_printf("%#X ", LONG_MIN);
	compare_printf("%#X ", INT_MAX);
	compare_printf("%#X ", INT_MIN);
	compare_printf("%#X ", LONG_MAX);
	compare_printf("%#X ", LONG_MIN);
	compare_printf("%#X ", ULONG_MAX);
	compare_printf("%#X ", -42);

	compare_printf("\\!/%- 18.2d\\!/", 0);
	compare_printf(">------------<%#16.41x>------------<", -1661147392);
	compare_printf("%04u ", 9);
	compare_printf("%01u ", 10);
	compare_printf("%04u ", 16);
	compare_printf("%05u ", 17);
	compare_printf("%01u ", 99);
	compare_printf("%012u ", LONG_MIN);
	compare_printf("%013u ", UINT_MAX);
	compare_printf("%014u ", ULONG_MAX);
	compare_printf("%015u ", 9223372036854775807LL);

	compare_printf("%09u ", INT_MAX);
	compare_printf("%010u ", INT_MIN);
	compare_printf("%011u ", LONG_MAX);
	compare_printf("%012u ", LONG_MIN);
	compare_printf("%013u ", ULONG_MAX);
	compare_printf("%014u ", 0);
	compare_printf("%015u ", -42);*/
	// compare_printf("%01x ", 0);
	// compare_printf("%04x ", 9);
	// compare_printf("%01x ", 10);
	// compare_printf("%03x ", 15);
	// compare_printf("%04x ", 16);
	// compare_printf("%05x ", 17);
	// compare_printf("%01x ", 99);
	// compare_printf("%01x ", -9);
	// compare_printf("%010x ", INT_MIN);
	// compare_printf("%x ", -1);
	// compare_printf("%x ", 10);
	// compare_printf("%x ", 11);
	// compare_printf("%x ", 15);
	// compare_printf("%x ", -9);
	// compare_printf("%x ", -10);
	// compare_printf("%x ", -11);
	// compare_printf("%x ", -14);
	// compare_printf("%x ", -15);
	// compare_printf("%x ", -16);
	// compare_printf("%x ", -99);
	// compare_printf("%x ", -100);
	// char *s_hidden = "nic";

	// compare_printf("%-9.8s", NULL);
	// compare_printf("%.0s", "hello");
	// compare_printf("%.s", "NULL");
	// compare_printf("%.0s", "NULL");
	// compare_printf("%.s", s_hidden);
	// compare_printf("%3.s", s_hidden);
	// compare_printf("%10.s", s_hidden);
	// compare_printf("%-3.s", s_hidden);
	// compare_printf("%-8.s", s_hidden);
	// compare_printf("%-.00s", s_hidden);

	compare_printf(" %p ", -1);
	compare_printf(" %p ", 1);
	compare_printf(" %p ", 15);
	compare_printf(" %p ", 16);
	compare_printf(" %p ", 17);
	compare_printf(" %p  ", LONG_MIN);
	compare_printf(" %p  ", INT_MIN);
	compare_printf(" %p ", ULONG_MAX);
	compare_printf(" %p  ", 0);
}

#include <stdio.h>
#include <stdint.h>
#include <math.h>
int main ()
{
	int32_t loan_date1 = 0;
	int32_t loan_date2 = 0;
	int32_t loan_term1 = 0;
	double property_tax = 0;
	double insurance = 0;
	double additional_payment = 0;
	double total_monthly_payment = 0;
	double loan_price = 0;
	double interest_rate = 0;
	double interest_rate1 = 0;
	double loan_term2 = 0;
	double principal = 0;
	double remaining = 0;
	double interest_rate2 = 0;
	double principal1 = 0;

	printf( "Loan Date:" );
	scanf( "%d" "." "%d" , &loan_date1 , &loan_date2 );
	printf( "Loan Price:" );
	scanf( "%lf" , &loan_price );
	printf( "Loan Term ""(yrs):" );
	scanf( "%d" , &loan_term1 );
	printf( "Interest Rate (%%):" );
	scanf( "%lf" , &interest_rate );
	printf( "Property Tax ""(/m):" );
	scanf( "%lf" , &property_tax );
	printf( "Insurance ""(/m):" );
	scanf( "%lf" , &insurance );
	printf( "Additional Payment ""(/m):" );
	scanf( "%lf" , &additional_payment );
	printf( "---Output---\n" );
	
	loan_term2 = loan_term1 * 12;
	interest_rate1 = (interest_rate * 0.01) / 12;
	
	//第一次的運算式
	principal = (float)(loan_price * (interest_rate1 * (pow((1 + interest_rate1) , loan_term2))) / (pow((1 + interest_rate1) , loan_term2) - 1)) + additional_payment - remaining * interest_rate2;
	total_monthly_payment = principal + property_tax + insurance;
	interest_rate2 = loan_price * interest_rate1;
	principal1 = principal - interest_rate2;
	remaining = loan_price - principal1;
	 
	//error input
	if( loan_term1 != 10 && loan_term1 != 15 && loan_term1 != 20 && loan_term1 != 30){
		printf( "Error loan term input.\n" );
		return 0;
	} 
	if( loan_date2 > 12 ){
		printf( "Error month input.\n" );
	}

	remaining = loan_price;
	remaining = (int32_t)(remaining * 100 + 0.5) / 100.0;
	//開始計算
	for( int32_t i = 1 ; i <= loan_term1 + 1 ; i++){
	
		while( loan_date2 <= 12 ){
			if( remaining > 1){
				/*remaining = (int32_t)(remaining * 100 + 0.5) / 100.0;*/
				principal1 *= remaining;
				interest_rate2 = interest_rate1 * remaining;
				principal1 = principal - interest_rate2;

				printf( "%d"".""%02d)" , loan_date1 , loan_date2 );
				printf( "  Principal: $%.2f," , principal1 );
				printf( "  Interest: $%.2f," , interest_rate2 );
				remaining -= principal1;
				printf( "  Remaining: $%.2f\n" , remaining );
				loan_date2 += 1;
			}	
		}
		loan_date1 += 1;
		loan_date2 -= 12;
	}
	printf( "\n" );

	return 0;
}

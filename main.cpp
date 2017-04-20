#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>
#include "temperature.h"
using namespace std;

void test_temperature_input(){
    Temperature tempr;
    istringstream issK("10K");
    issK>>tempr;
    assert(tempr.temp ==10);
    assert(tempr.scale =='K');
    istringstream issF("10F");
    issF>>tempr;
    assert(tempr.temp ==10);
    assert(tempr.scale =='F');
    istringstream issC("10C");
    issC>>tempr;
    assert(tempr.temp ==10);
    assert(tempr.scale =='C');

}


int main()
{

    Temperature tempr;
    cout<<tempr.scale;
    cout<<tempr.temp;
    cin>>tempr;
vector <Temperature>tempr(number_count);

    const double kelvins=convert(num,'K').value;
    const double min_k=convert(num,'K').value;
    const double max_k=convert(num,'K').value;
    tempr.temp = convert(tempr.temp,tempr.scale,'C');
    tempr.scale='C';
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;
vector <size_t> counts()
    cerr << "Enter numbers: ";
    vector<double> tempr(number_count);
    for (size_t i = 0; i < number_count; i++) {
        cin >> tempr[i];
    }

    size_t column_count;
    cerr << "Enter column count: ";
    cin >> column_count;

    double min = tempr[0];
    double max = tempr[0];
    for (double number : tempr) {
        if (number < min) {
            min = number;
        }
        if (number > max) {
            max = number;
        }
    }

    vector<size_t> counts(column_count);
    for (double number : tempr) {
        size_t column = (size_t)((number - min) / (max - min) * column_count);
        if (column == column_count) {
            column--;
        }
        counts[column]++;
    }

    const size_t screen_width = 80;
    const size_t axis_width = 4;
    const size_t chart_width = screen_width - axis_width;


    size_t max_count = 0;
    for (size_t count : counts) {
        if (count > max_count) {
            max_count = count;
        }
    }
    const bool scaling_needed = max_count > chart_width;

    for (size_t count : counts) {
        if (count < 100) {
            cout << ' ';
        }
        if (count < 10) {
            cout << ' ';
        }
        cout << count << "|";

        size_t height = count;
        if (scaling_needed) {
            const double scaling_factor = (double)chart_width / max_count;
            height = (size_t)(count * scaling_factor);
        }

        for (size_t i = 0; i < height; i++) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}
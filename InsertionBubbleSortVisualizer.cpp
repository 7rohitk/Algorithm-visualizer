#include <graphics.h>
#include <bits/stdc++.h>
#include <algorithm>
#include <conio.h>

using namespace std;



 
vector<vector<int>> bubbleSort(vector<int> arr)
{
    vector<vector<int>> states;
    int n = arr.size();

    states.push_back(arr);  

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                states.push_back(arr); 
            }
        }
    }
    return states;
}



 
vector<vector<int>> insertionSort(vector<int> arr)
{
    vector<vector<int>> states;
    int n = arr.size();

    states.push_back(arr); // Initial state
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        states.push_back(arr);  
    }

    return states;
}



// Function to visualize sorting states
void visualizeSort( vector<vector<int>> &states, int barColor)
{
    int maxVal = 0;

    for ( auto &state : states)
    {
        for (int val : state)
        {
            if (val > maxVal)
            {
                maxVal = val;
            }
        }
    }

    int barWidth = 640 / states[0].size(); 
    int currentState = 0;

    initwindow(640, 480); 

    while (true)
    {
        if (kbhit())
        {
            char ch = getch();
            if (ch == 27) 
                break;
        }

        cleardevice();

        // Draw current state
        for (size_t i = 0; i < states[currentState].size(); i++)
        {
            int barHeight = (states[currentState][i] * 480) / maxVal;  
            if (barColor == 1)
                setfillstyle(SOLID_FILL, BLUE);  
            else
                setfillstyle(SOLID_FILL, RED); 
            bar(i * barWidth, 480 - barHeight, (i + 1) * barWidth, 480);
        }

        delay(500);  
        currentState = (currentState + 1) % states.size();
    }

    closegraph(); 
}

int main()
{
    vector<int> arr = {50, 30, 20, 10, 40, 60, 70, 40};

    // Visualize Bubble Sort (blue bars)
    vector<vector<int>> bubbleStates = bubbleSort(arr);
    visualizeSort(bubbleStates, 1);  


    // press esc key for insertion sort 


    // Visualize Insertion Sort (red bars)
    vector<vector<int>> insertionStates = insertionSort(arr);
    visualizeSort(insertionStates, 2); 
    return 0;
}

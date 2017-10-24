#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Meeting
{
private:
        // number of 30 min blocks past 9:00 am
        unsigned int startTime_;
        unsigned int endTime_;

public:
    Meeting() :
        startTime_(0),
        endTime_(0)
    {
    }

    Meeting(unsigned int startTime, unsigned int endTime) :
        startTime_(startTime),
        endTime_(endTime)
    {
    }

    unsigned int getStartTime() const
    {
        return startTime_;
    }

    void setStartTime(unsigned int startTime)
    {
        startTime_ = startTime;
    }

    unsigned int getEndTime() const
    {
        return endTime_;
    }

    void setEndTime(unsigned int endTime)
    {
        endTime_ = endTime;
    }

    bool operator==(const Meeting& other) const
    {
        return
            startTime_ == other.startTime_
            && endTime_ == other.endTime_;
    }

    bool operator< (const Meeting &other) const
    {
        return startTime_ < other.getStartTime();
    }
};

void print_meetings(vector <Meeting> input)
{
    for (int i = 0; i < input.size(); i++)
    {
        cout << "Meeting #: " << i+1 << endl;
        cout << "Start Time: " << input[i].getStartTime() << endl;
        cout << "End Time: " << input[i].getEndTime() << endl << endl;
    }
}

vector <Meeting> mergeRanges(vector <Meeting> input)
{
    // Sort meetings based on start time
    sort(input.begin(), input.end());

    // Initialize output
    vector <Meeting> output;

    // Store first meeting
    Meeting currentMeeting = input[0];
    int startTime = input[0].getStartTime();
    int endTime = input[0].getEndTime();
    
    // Go through remaining calendar and identify merges
    for (int i = 1; i < input.size(); i++)
    {
        while (input[i].getStartTime() <= endTime && input[i].getStartTime() > startTime)
        {
            endTime = (input[i].getEndTime() > endTime) ? input[i].getEndTime() : endTime;
            i++;
        }

        output.push_back(Meeting(startTime, endTime));
        startTime = input[i].getStartTime();
        endTime = input[i].getEndTime();
    }
    
    return output;
}

int main()
{
    vector <Meeting> testInput = {Meeting(0, 1), Meeting(10, 12), Meeting(3, 5), Meeting(9, 10), Meeting(4, 8)};
    print_meetings(mergeRanges(testInput));

    return 0;
}
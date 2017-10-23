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
    vector <Meeting> output;
    vector <bool> partOfMerge(input.size(), false);
    
    for (int i = 0; i < input.size(); i++)
    {
        Meeting currentMeeting = input[i];
        int startTime = currentMeeting.getStartTime();
        int endTime = currentMeeting.getEndTime();

        for (int j = i + 1; j < input.size(); j++)
        {
            if (input[j].getStartTime() < endTime && input[j].getStartTime() > startTime)
            {
                output.push_back(Meeting(startTime, input[j].getEndTime()));
                partOfMerge[i] = true;
                partOfMerge[j] = true;
            }
            else if (input[j].getEndTime() < endTime && input[j].getEndTime() >= startTime)
            {
                output.push_back(Meeting(input[j].getStartTime(), endTime));
                partOfMerge[i] = true;
                partOfMerge[j] = true;
            }
        }
        if (!partOfMerge[i])
            output.push_back(currentMeeting);
    }
    return output;
}

int main()
{
    vector <Meeting> testInput = {Meeting(0,1), Meeting(3,5), Meeting(4,8), Meeting(10,12), Meeting(9,10)};
    print_meetings(mergeRanges(testInput));

    return 0;
}
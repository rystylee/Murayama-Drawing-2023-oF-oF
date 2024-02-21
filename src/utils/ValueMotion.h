#pragma once

#include "ofMain.h"

#include "ofxChoreograph.h"


template <typename T> class ValueMotion
{
public:
    struct MotionData
    {
        T startVal;
        T endVal;
        float duration;
        ofxChoreograph::EaseFn easeFn;
    };

    void update()
    {
        _timeline.step(ofGetLastFrameTime());
    }

    bool bang(const MotionData& motionData)
    {
        if (!_timeline.empty()) return false;

        _timeline.apply(&_value).template then<ofxChoreograph::RampTo>(motionData.startVal, 0.0, motionData.easeFn);
        _timeline.append(&_value).template then<ofxChoreograph::RampTo>(motionData.endVal, motionData.duration, motionData.easeFn);
        return true;
    }

    bool bang(const std::vector<MotionData>& motionData)
    {
        if (!_timeline.empty()) return false;

        _timeline.apply(&_value).template then<ofxChoreograph::RampTo>(motionData[0].startVal, 0.0, motionData[0].easeFn);
        for (auto e : motionData)
        {
            _timeline.append(&_value).template then<ofxChoreograph::RampTo>(e.endVal, e.duration, e.easeFn);
        }
        return true;
    }

    const T& getValue() { return _value.value(); }
    const bool isEmpty() { return _timeline.empty(); }

private:
    ofxChoreograph::Timeline _timeline;
    ofxChoreograph::Output<T> _value;

};

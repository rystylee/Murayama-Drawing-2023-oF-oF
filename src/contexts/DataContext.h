#pragma once

#include "ofMain.h"

#include "../utils/ValueMotion.h"

#include "ofxGlobalContext.h"
#include "ofxImGui.h"

class DataContext final : public ofxGlobalContext::Context
{
public:
    DataContext()
    {
        initImages();
        initPhaseIndices();
        initPhaseSelectIndices();
    }

    void update() override
    {
    }

    void renderGui()
    {
        ImGui::Begin("Data Context");
        {
        }
        ImGui::End();
    }

    const std::vector<ofImage>& getImages() { return _images; }
    const std::vector<std::vector<int>>& getPhaseIndices() { return _phaseIndices; }
    const std::vector<std::vector<int>>& getPhaseSelectIndices() { return _phaseSelectIndices; }

private:
    void initImages()
    {
        ofDisableArbTex();
        for (int i = 0; i < 602; i++)
        {
            _images.emplace_back(ofImage("images/data_all/" + ofToString(i+1) + ".JPG"));
        }
        ofEnableArbTex();
    }

    void initPhaseIndices()
    {
        std::vector<int> phase1;
        for (int i = 1; i < 84; i++) phase1.emplace_back(i);
        _phaseIndices.push_back(phase1);
    
        std::vector<int> phase2;
        for (int i = 84; i < 135; i++) phase2.emplace_back(i);
        _phaseIndices.push_back(phase2);
    
        std::vector<int> phase3;
        for (int i = 135; i < 174; i++) phase3.emplace_back(i);
        _phaseIndices.push_back(phase3);
    
        std::vector<int> phase4;
        for (int i = 174; i < 226; i++) phase4.emplace_back(i);
        _phaseIndices.push_back(phase4);
    
        std::vector<int> phase5;
        for (int i = 226; i < 290; i++) phase5.emplace_back(i);
        _phaseIndices.push_back(phase5);
    
        std::vector<int> phase6;
        for (int i = 290; i < 337; i++) phase6.emplace_back(i);
        _phaseIndices.push_back(phase6);
    
        std::vector<int> phase7;
        for (int i = 337; i < 425; i++) phase7.emplace_back(i);
        _phaseIndices.push_back(phase7);
    
        std::vector<int> phase8;
        for (int i = 425; i < 487; i++) phase8.emplace_back(i);
        _phaseIndices.push_back(phase8);
    
        std::vector<int> phase9;
        for (int i = 487; i < 568; i++) phase9.emplace_back(i);
        _phaseIndices.push_back(phase9);
    
        std::vector<int> phase10;
        for (int i = 568; i < 591; i++) phase10.emplace_back(i);
        _phaseIndices.push_back(phase10);
    
        std::vector<int> phase11;
        for (int i = 591; i < 603; i++) phase11.emplace_back(i);
        _phaseIndices.push_back(phase11);
    }
    
    void initPhaseSelectIndices()
    {
        _phaseSelectIndices.emplace_back(std::vector<int>{
            13, 15, 23, 25, 28, 29, 30, 32, 35, 42, 43, 50, 52, 55, 56, 57, 60, 62, 66, 68, 69, 70, 71, 73, 74, 76, 77, 78, 81, 82
        });
        _phaseSelectIndices.emplace_back(std::vector<int>{
            85, 92, 95, 96, 98, 99, 100, 106, 108, 109, 116, 117, 122, 123, 124, 126, 129, 131, 132, 134
        });
        _phaseSelectIndices.emplace_back(std::vector<int>{
            136, 138, 139, 141, 144, 145, 149, 151, 152, 155, 157, 158, 159, 162, 163, 165, 166, 167, 170
        });
        _phaseSelectIndices.emplace_back(std::vector<int>{
            173, 175, 176, 178, 179, 181, 184, 186, 191, 192, 197, 198, 199, 201, 204, 207, 209, 211, 212, 213, 215, 216, 219, 221, 224
        });
        _phaseSelectIndices.emplace_back(std::vector<int>{
            225, 229, 241, 242, 243, 230, 231, 232, 233, 234, 235, 236, 238, 246, 248, 249, 250, 252, 256, 257, 258, 261, 263, 265, 267, 270, 272, 280, 281, 286, 287
        });
        _phaseSelectIndices.emplace_back(std::vector<int>{
            291, 295, 296, 297, 298, 305, 310, 313, 314, 315, 316, 328, 332, 334, 336
        });
        _phaseSelectIndices.emplace_back(std::vector<int>{
            338, 346, 348, 352, 359, 367, 368, 369, 371, 377, 378, 379, 380, 382, 383, 386, 387, 388, 389, 391, 393, 394, 396, 397, 398, 399, 401, 402, 404, 412, 414, 419, 420, 421, 422
        });
        _phaseSelectIndices.emplace_back(std::vector<int>{
            427, 429, 433, 436, 443, 444, 448, 450, 453, 455, 456, 460, 462, 465, 466, 468, 471, 472, 473, 474, 476, 477, 480, 482, 483
        });
        _phaseSelectIndices.emplace_back(std::vector<int>{
            488, 489, 491, 494, 495, 497, 500, 501, 502, 503, 505, 506, 511, 513, 514, 515, 516, 517, 518, 520, 521, 522, 526, 527, 528, 529, 531, 532, 533, 534, 535, 536, 537, 538, 541, 543, 545, 546, 549, 550, 552, 553, 554, 556, 557, 560, 563, 564, 566, 567
        });
        _phaseSelectIndices.emplace_back(std::vector<int>{
            568, 569, 570, 571, 573, 575, 576, 577, 578, 580, 582, 583, 586, 588, 590
        });
        _phaseSelectIndices.emplace_back(std::vector<int>{
            591, 592, 593, 595, 596, 597, 599, 600, 603, 604
        });
    }
    
    std::vector<ofImage> _images;

    std::vector<std::vector<int>> _phaseIndices;
    std::vector<std::vector<int>> _phaseSelectIndices;

};

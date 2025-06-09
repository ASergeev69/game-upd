#pragma once

class Screen {
public:
    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual ~Screen() = default;
};
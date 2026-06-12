#pragma once

class Uptadable
{
public:
    virtual ~Uptadable() = default;

    virtual void update() = 0;
};
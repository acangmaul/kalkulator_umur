#pragma once

template <typename T>
struct Badge final {
private:
    friend T;
    Badge() { }
};

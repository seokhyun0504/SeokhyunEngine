#include "AABB.h"

template <typename T, glm::length_t N>
AABB<T, N>::AABB()
{
    for (glm::length_t i = 0; i < N; ++i)
    {
        min[i] = std::numeric_limits<T>::max();
        max[i] = std::numeric_limits<T>::lowest();
    }
}

template <typename T, glm::length_t N>
AABB<T, N>::AABB(const glm::vec<N, T>& minPoint, const glm::vec<N, T>& maxPoint)
    : min(minPoint), max(maxPoint)
{

}

template <typename T, glm::length_t N>
AABB<T, N>::AABB(const glm::vec<N, T>& point)
    : min(point), max(point)
{

}

template <typename T, glm::length_t N>
bool AABB<T, N>::isValid() const
{
    for (glm::length_t i = 0; i < N; ++i)
    {
        if (min[i] > max[i]) return false;
    }

    return true;
}


template <typename T, glm::length_t N>
void AABB<T, N>::expand(const glm::vec<N, T>& p)
{
    for (glm::length_t i = 0; i < N; ++i)
    {
        if (p[i] < min[i]) min[i] = p[i];
        if (p[i] > max[i]) max[i] = p[i];
    }
}

template <typename T, glm::length_t N>
void AABB<T, N>::expand(const AABB& box)
{
    for (glm::length_t i = 0; i < N; ++i)
    {
        if (box.min[i] < min[i]) min[i] = box.min[i];
        if (box.max[i] > max[i]) max[i] = box.max[i];
    }
}

template <typename T, glm::length_t N>
bool AABB<T, N>::contains(const glm::vec<N, T>& p) const
{
    for (glm::length_t i = 0; i < N; ++i)
    {
        if (p[i] < min[i] || p[i] > max[i])
            return false;
    }

    return true;
}

template <typename T, glm::length_t N>
bool AABB<T, N>::contains(const AABB& box) const
{
    for (glm::length_t i = 0; i < N; ++i)
    {
        if (box.min[i] < min[i] || box.max[i] > max[i])
            return false;
    }

    return true;
}

template <typename T, glm::length_t N>
bool AABB<T, N>::intersects(const AABB& box) const
{
    for (glm::length_t i = 0; i < N; ++i)
    {
        if (max[i] < box.min[i] || min[i] > box.max[i])
            return false;
    }
    
    return true;
}

template <typename T, glm::length_t N>
AABB<T, N> AABB<T, N>::intersection(const AABB& box) const
{
    AABB<T, N> result;
    for (glm::length_t i = 0; i < N; ++i)
    {
        result.min[i] = std::max(min[i], box.min[i]);
        result.max[i] = std::min(max[i], box.max[i]);
    }

    return result;
}

template <typename T, glm::length_t N>
AABB<T, N> AABB<T, N>::unify(const AABB& box) const
{
    AABB<T, N> result;
    for (glm::length_t i = 0; i < N; ++i)
    {
        result.min[i] = std::min(min[i], box.min[i]);
        result.max[i] = std::max(max[i], box.max[i]);
    }

    return result;
}

template <typename T, glm::length_t N>
glm::vec<N, T> AABB<T, N>::center() const
{
    return (min + max) * static_cast<T>(0.5);
}

template <typename T, glm::length_t N>
glm::vec<N, T> AABB<T, N>::size() const
{
    return max - min;
}

template <typename T, glm::length_t N>
T AABB<T, N>::volume() const
{
    glm::vec<N, T> s = size();
    T vol = static_cast<T>(1);

    for (glm::length_t i = 0; i < N; ++i)
    {
        vol *= s[i];
    }

    return vol;
}

template <typename T, glm::length_t N>
AABB<T, N> AABB<T, N>::operator | (const AABB& rhs) const
{
    return unify(rhs);
}

template <typename T, glm::length_t N>
AABB<T, N> AABB<T, N>::operator & (const AABB& rhs) const
{
    return intersection(rhs);
}

template struct AABB<float, 2>;
template struct AABB<float, 3>;
template struct AABB<double, 2>;
template struct AABB<double, 3>;
template struct AABB<int, 2>;
template struct AABB<int, 3>;
#ifndef __AABB_H__
#define __AABB_H__

#include <algorithm>
#include <limits>

#include "common.h"

/**
 * @class AABB
 * @brief A structure implementing an Axis-Aligned Bounding Box (AABB).
 *
 * @tparam T Scalar type (e.g., float, double, int).
 * @tparam N Dimension count (1 or higher).
 *
 * @details
 *   - Represents an AABB using `min` and `max` vectors, with flexibility provided by template parameters.
 */
template <typename T, glm::length_t N>
struct AABB
{

public:

    glm::vec<N, T> min;
    glm::vec<N, T> max;

    /**
     * @brief Default constructor
     *
     * Initializes `min` to +INF and `max` to -INF, representing an "empty" state.
     */
    AABB();

    /**
     * @brief Initializes the AABB with the given `min` and `max`.
     *
     * @param minPoint Minimum coordinate of the AABB.
     * @param maxPoint Maximum coordinate of the AABB.
     */
    AABB(const glm::vec<N, T>& minPoint, const glm::vec<N, T>& maxPoint);

    /**
     * @brief Initializes the AABB from a single point.
     *
     * Both `min` and `max` are set to the same point.
     * @param point The point defining the AABB.
     */
    AABB(const glm::vec<N, T>& point);

    /**
     * @brief Checks if the AABB is valid (i.e., min <= max).
     * @return True if valid, false otherwise.
     */
    bool isValid() const;

    /**
     * @brief Expands the AABB to include the given point `p`.
     * @param p The point to include.
     *
     * Updates `min` and `max` by comparing them with `p`.
     */
    void expand(const glm::vec<N, T>& p);

    /**
     * @brief Expands the AABB to include another AABB.
     * @param box The AABB to include.
     */
    void expand(const AABB& box);

    /**
     * @brief Checks if the given point `p` lies inside (or on the boundary of) the AABB.
     * @param p The point to check.
     * @return True if the point is inside, false otherwise.
     */
    bool contains(const glm::vec<N, T>& p) const;

    /**
     * @brief Checks if another AABB is completely inside this AABB.
     * @param box The AABB to check.
     * @return True if the AABB is inside, false otherwise.
     */
    bool contains(const AABB& box) const;

    /**
     * @brief Checks if this AABB intersects (collides with) another AABB.
     * @param box The AABB to check.
     * @return True if they intersect, false otherwise.
     */
    bool intersects(const AABB& box) const;

    /**
     * @brief Returns the intersection area of two AABBs.
     * @param box The AABB to intersect with.
     * @return The intersected AABB (may be invalid if they do not intersect).
     */
    AABB intersection(const AABB& box) const;

    /**
     * @brief Returns the union (smallest AABB enclosing both) of two AABBs.
     * @param box The AABB to unify with.
     * @return The unified AABB.
     */
    AABB unify(const AABB& box) const;

    /**
     * @brief Returns the center point of the AABB.
     * @return (min + max) / 2
     */
    glm::vec<N, T> center() const;

    /**
     * @brief Returns the size (extent) of the AABB along each axis.
     * @return size[i] = max[i] - min[i]
     */
    glm::vec<N, T> size() const;

    /**
     * @brief Computes the "volume" of the N-dimensional AABB.
     * @return The volume (product of all size components).
     */
    T volume() const;

    /**
     * @brief Overloads the union operator.
     * @details lhs | rhs == lhs.unify(rhs)
     */
    AABB operator | (const AABB& rhs) const;

    /**
     * @brief Overloads the intersection operator.
     * @details lhs & rhs == lhs.intersection(rhs)
     */
    AABB operator & (const AABB& rhs) const;
};


typedef AABB<float, 2> AABB2;
typedef AABB<float, 3> AABB3;
typedef AABB<double, 2> AABB2d;
typedef AABB<double, 3> AABB3d;
typedef AABB<int, 2> AABB2i;
typedef AABB<int, 3> AABB3i;


#endif //__AABB_H__
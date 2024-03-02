#include <gtest/gtest.h>
#include "src/farray.hpp"

TEST(test_1, create_trapezoid) {
    Trapezoid Trapezoid;
    ASSERT_TRUE(Trapezoid.is_correct());
}

TEST(test_2, create_rhomb) {
    Rhomb rh;
    ASSERT_TRUE(rh.is_correct());
}

TEST(test_3, create_pentagon) {
    Pentagon pen;
    ASSERT_TRUE(pen.is_correct());
}

TEST(test_4, create_trapezoid_with_points) {
    Point p1(1, 1), p2(3, 4), p3(6, 4), p4(8, 1);
    Trapezoid trapezoid(p1, p2, p3, p4);
    ASSERT_TRUE(trapezoid.is_correct());
}

TEST(test_5, create_rhomb_with_points) {
    Point r1(3, 1), r2(1, 4), r3(3, 7), r4(5, 4);
    Rhomb rh(r1, r2, r3, r4);
    ASSERT_TRUE(rh.is_correct());
}

TEST(test_6, create_pentagon_with_points) {
    Point p1(2, 1), p2(1, 4), p3(4, 6), p4(7, 4), p5(6, 1);
    Pentagon pen(p1, p2, p3, p4, p5);
    ASSERT_TRUE(pen.is_correct());
}

TEST(test_7, create_bad_trapezoid_with_points) {
    Point p1(1, 1), p2(1, 1), p3(1, 1), p4(1, 1);
    bool check = true;
    try {
        Trapezoid Trapezoid(p1, p2, p3, p4);
    }
    catch (std::exception &ex)  {
        check = false;
    }
    ASSERT_FALSE(check);
}

TEST(test_8, create_bad_rhomb_with_points) {
    Point r1(1, 1), r2(1, 1), r3(1, 1), r4(1, 1);
    bool check = true;
    try {
        Rhomb rh(r1, r2, r3, r4);
    }
    catch (std::exception &ex)  {
        check = false;
    }
    ASSERT_FALSE(check);
}

TEST(test_9, create_bad_pentagon_with_points) {
    Point p1(1, 1), p2(1, 1), p3(1, 1), p4(7, 4), p5(6, 1);
    bool check = true;
    try {
        Pentagon pen(p1, p2, p3, p4, p5);
    }
    catch (std::exception &ex)  {
        check = false;
    }
    ASSERT_FALSE(check);
}

TEST(test_10, find_trapezoid_center) {
    Point p1(1, 1), p2(3, 5), p3(7, 5), p4(9, 1);
    Trapezoid Trapezoid(p1, p2, p3, p4);
    Point center = Trapezoid.center();
    Point exp_center(5, 3);
    ASSERT_TRUE(center.Equal(exp_center));
}

TEST(test_11, find_rhomb_center) {
    Point p1(1, 4), p2(3, 7), p3(5, 4), p4(3, 1);
    Rhomb rh(p1, p2, p3, p4);
    Point center = rh.center();
    Point exp_center(3, 4);
    ASSERT_TRUE(center.Equal(exp_center));
}

TEST(test_12, find_pentagon_center) {
    Point p1(2, 1), p2(1, 4), p3(3, 5), p4(5, 4), p5(4, 1);
    Pentagon pen(p1, p2, p3, p4, p5);
    Point center = pen.center();
    Point exp_center(3, 3);
    ASSERT_TRUE(center.Equal(exp_center));
}

TEST(test_13, find_trapezoid_area) {
    Point p1(1, 1), p2(3, 4), p3(6, 4), p4(8, 1);
    Trapezoid Trapezoid(p1, p2, p3, p4);
    double area = Trapezoid.getArea();
    double exp_area = 15.0;
    ASSERT_TRUE(area == exp_area);
}

TEST(test_14, find_rhomb_area) {
    Point r1(3, 1), r2(1, 4), r3(3, 7), r4(5, 4);
    Rhomb rh(r1, r2, r3, r4);
    double area = rh.getArea();
    double exp_area = 12.0;
    ASSERT_TRUE(area == exp_area);
}

TEST(test_15, find_pentagon_area) {
    Point p1(1, 3), p2(3, 5), p3(5, 3), p4(4, 1), p5(2, 1);
    Pentagon pen(p1, p2, p3, p4, p5);
    double area = pen.getArea();
    double exp_area = 10.0;
    ASSERT_TRUE(area == exp_area);
}

TEST(test_16, copy_operator_trapezion) {
    Point p1(1, 1), p2(3, 4), p3(6, 4), p4(8, 1);
    Trapezoid trapezoid1(p1, p2, p3, p4);
    Trapezoid trapezoid2;
    trapezoid2 = trapezoid1;
    ASSERT_TRUE((trapezoid1 == trapezoid2) and (trapezoid1.center().Equal(trapezoid2.center())) and (trapezoid1.getArea() == trapezoid2.getArea()));
}

TEST(test_17, move_operator_trapezoid) {
    Point p1(1, 1), p2(3, 4), p3(6, 4), p4(8, 1);
    Trapezoid trapezoid1(p1, p2, p3, p4);
    Trapezoid trapezoid2;
    trapezoid2 = std::move(trapezoid1);
    ASSERT_TRUE((trapezoid1 == trapezoid2) and (trapezoid1.center().Equal(trapezoid2.center())) and (trapezoid1.getArea() == trapezoid2.getArea()));
}

TEST(test_18, copy_operator_rhomb) {
    Point r1(3, 1), r2(1, 4), r3(3, 7), r4(5, 4);
    Rhomb rh1(r1, r2, r3, r4);
    Rhomb rh2;
    rh2 = rh1;
    ASSERT_TRUE((rh1 == rh2) and (rh1.center().Equal(rh2.center())) and (rh1.getArea() == rh2.getArea()));
}

TEST(test_19, move_operator_rhomb) {
    Point r1(3, 1), r2(1, 4), r3(3, 7), r4(5, 4);
    Rhomb rh1(r1, r2, r3, r4);
    Rhomb rh2;
    rh2 = std::move(rh1);
    ASSERT_TRUE((rh1 == rh2) and (rh1.center().Equal(rh2.center())) and (rh1.getArea() == rh2.getArea()));
}

TEST(test_20, copy_operator_pentagon) {
    Point p1(1, 3), p2(3, 5), p3(5, 3), p4(4, 1), p5(2, 1);
    Pentagon pen1(p1, p2, p3, p4, p5);
    Pentagon pen2;
    pen2 = pen1;
    ASSERT_TRUE((pen1 == pen2) and (pen1.center().Equal(pen2.center())) and (pen1.getArea() == pen2.getArea()));
}

TEST(test_21, move_operator_pentagon) {
    Point p1(1, 3), p2(3, 5), p3(5, 3), p4(4, 1), p5(2, 1);
    Pentagon pen1(p1, p2, p3, p4, p5);
    Pentagon pen2;
    pen2 = std::move(pen1);
    ASSERT_TRUE((pen1 == pen2) and (pen1.center().Equal(pen2.center())) and (pen1.getArea() == pen2.getArea()));
}

TEST(test_22, Figure_array_add) {
    Point t1(1, 1), t2(3, 4), t3(6, 4), t4(8, 1);
    Trapezoid trp(t1, t2, t3, t4);

    Point r1(3, 1), r2(1, 4), r3(3, 7), r4(5, 4);
    Rhomb rh(r1, r2, r3, r4);

    Point p1(1, 3), p2(3, 5), p3(5, 3), p4(4, 1), p5(2, 1);
    Pentagon pen(p1, p2, p3, p4, p5);

    Farray *far = create_arr();
    add_figure(far, trp);
    add_figure(far, rh);
    add_figure(far, pen);
    ASSERT_TRUE(far->size == 3);
}

TEST(test_23, Figure_array_sum_area) {
    Point t1(1, 1), t2(3, 4), t3(6, 4), t4(8, 1);
    Trapezoid trp(t1, t2, t3, t4);

    Point r1(3, 1), r2(1, 4), r3(3, 7), r4(5, 4);
    Rhomb rh(r1, r2, r3, r4);

    Point p1(1, 3), p2(3, 5), p3(5, 3), p4(4, 1), p5(2, 1);
    Pentagon pen(p1, p2, p3, p4, p5);

    Farray *far = create_arr();
    add_figure(far, trp);
    add_figure(far, rh);
    add_figure(far, pen);
    ASSERT_TRUE(sum_area(far) == 37);
}

TEST(test_24, Figure_array_rm_figure) {
    Point t1(1, 1), t2(3, 4), t3(6, 4), t4(8, 1);
    Trapezoid trp(t1, t2, t3, t4);

    Point r1(3, 1), r2(1, 4), r3(3, 7), r4(5, 4);
    Rhomb rh(r1, r2, r3, r4);

    Point p1(1, 3), p2(3, 5), p3(5, 3), p4(4, 1), p5(2, 1);
    Pentagon pen(p1, p2, p3, p4, p5);

    Farray *far = create_arr();
    add_figure(far, trp);
    add_figure(far, rh);
    add_figure(far, pen);
    far->arr = rm_figure(far, 0);
    far->size--;
    ASSERT_TRUE(far->size == 2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
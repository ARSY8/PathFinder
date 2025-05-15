#include <gtest/gtest.h>
#include "PathFinder.hpp"
#include "FileReaderWriter.hpp"


std::vector<int> maze {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 2, 0, 1, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 1, 0, 0, 1, 0, 0, 1,
    1, 0, 0, 1, 0, 0, 1, 0, 0, 3,
    1, 0, 0, 0, 0, 0, 1, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};

std::vector<int> maze1 {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 2, 0, 1, 1, 0, 0, 0, 1, 1,
    1, 0, 0, 1, 0, 0, 1, 0, 0, 1,
    1, 0, 0, 1, 0, 0, 1, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 1, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};

std::vector<int> maze2 {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 2, 0, 1, 0, 0, 0, 0, 1, 1,
    1, 0, 0, 1, 0, 0, 1, 0, 0, 1,
    1, 0, 0, 1, 0, 0, 1, 0, 0, 3,
    1, 0, 0, 1, 0, 0, 1, 0, 0, 1,
    1, 0, 0, 1, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};

std::vector<int> maze3 {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 2, 0, 0, 1, 0, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 0, 0, 1, 0, 1,
    1, 0, 1, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 1, 1, 1, 1, 1, 1, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 3, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};

TEST(PathFinderTest, PathExists) {
    EXPECT_NO_THROW(PathFinder pathFinder1(maze, { 10, 7 }));

    EXPECT_ANY_THROW(PathFinder pathFinder2(maze1, { 10, 7 }));

    EXPECT_NO_THROW(PathFinder pathFinder3(maze2, { 10, 7 }));

    EXPECT_NO_THROW(PathFinder pathFinder4(maze3, { 10, 7 }));
}

TEST(PathFinderTest, ValidatePath) {
    PathFinder pathFinder_(maze, { 10, 7 });
    pathFinder_.getPath();
    
    EXPECT_EQ(maze[1 * 10 + 1], 8);
    EXPECT_EQ(maze[1 * 10 + 2], 8); 
    EXPECT_EQ(maze[2 * 10 + 2], 8); 
    EXPECT_EQ(maze[3 * 10 + 2], 8); 
    EXPECT_EQ(maze[4 * 10 + 2], 8); 
    EXPECT_EQ(maze[4 * 10 + 3], 8);
    EXPECT_EQ(maze[4 * 10 + 4], 8); 
    EXPECT_EQ(maze[4 * 10 + 5], 8); 
    EXPECT_EQ(maze[5 * 10 + 5], 8); 
    EXPECT_EQ(maze[5 * 10 + 6], 8); 
    EXPECT_EQ(maze[5 * 10 + 7], 8); 
    EXPECT_EQ(maze[5 * 10 + 8], 8); 
    EXPECT_EQ(maze[4 * 10 + 8], 8);
    EXPECT_EQ(maze[3 * 10 + 8], 8);
    EXPECT_EQ(maze[3 * 10 + 9], 8);
}

TEST(PathFinderTest, ValidatePath2) {
    PathFinder pathFinder2(maze3, { 10, 7 });
    pathFinder2.getPath();
    
    EXPECT_EQ(maze3[1 * 10 + 1], 8);
    EXPECT_EQ(maze3[1 * 10 + 2], 8);
    EXPECT_EQ(maze3[1 * 10 + 3], 8);
    EXPECT_EQ(maze3[2 * 10 + 3], 8);
    EXPECT_EQ(maze3[3 * 10 + 3], 8);
    EXPECT_EQ(maze3[3 * 10 + 4], 8);
    EXPECT_EQ(maze3[3 * 10 + 5], 8);
    EXPECT_EQ(maze3[3 * 10 + 6], 8);
    EXPECT_EQ(maze3[3 * 10 + 7], 8);
    EXPECT_EQ(maze3[3 * 10 + 8], 8);
    EXPECT_EQ(maze3[4 * 10 + 8], 8);
    EXPECT_EQ(maze3[5 * 10 + 8], 8);
}

#include <gtest/gtest.h>
#include "../Loader.h"

TEST(Loader, invalidFile) {
    vector<vec3> vertices;
    vector<vec2> uvs;
    vector<vec3> normals;
    vector<Triangle> triangles;

    bool success = Loader::loadObj("IDoNotExist.obj", &vertices, &uvs, &normals, &triangles);

    EXPECT_FALSE(success);
}

TEST(Loader, loadObjWithOnlyVertices) {
    /* Create a file */
    ofstream file;
    file.open("objWithOnlyVertices.obj");
    file << "v 0 0 0\n";
    file << "v 1 0 0\n";
    file << "v 0 1 0\n";
    file << "v 0 0 1\n";
    file.close();

    vector<vec3> vertices;
    vector<vec2> uvs;
    vector<vec3> normals;
    vector<Triangle> triangles;

    bool success = Loader::loadObj("objWithOnlyVertices.obj", &vertices, &uvs, &normals, &triangles);

    EXPECT_TRUE(success);

    EXPECT_EQ(vertices.size(), 4);
    EXPECT_EQ(vertices[0], vec3(0, 0, 0));
    EXPECT_EQ(vertices[1], vec3(1, 0, 0));
    EXPECT_EQ(vertices[2], vec3(0, 1, 0));
    EXPECT_EQ(vertices[3], vec3(0, 0, 1));

    EXPECT_EQ(uvs.size(), 0);
    EXPECT_EQ(normals.size(), 0);
    EXPECT_EQ(triangles.size(), 0);

    remove("objWithOnlyVertices.obj");
}

TEST(Loader, loadObjWithFacesAndVertices) {
    /* Create a file */
    ofstream file;
    file.open("objWithFacesAndVertices.obj");
    file << "v 0 0 0\n";
    file << "v 1 0 0\n";
    file << "v 0 1 0\n";
    file << "v 0 0 1\n";
    file << "f 1/0/0 1/0/0 3/0/0\n";
    file << "f 4/0/0 4/0/0 4/0/0\n";
    file << "f 3/0/0 1/0/0 1/0/0\n";
    file << "f 3/0/0 1/0/0 4/0/0\n";
    file.close();

    vector<vec3> vertices;
    vector<vec2> uvs;
    vector<vec3> normals;
    vector<Triangle> triangles;

    bool success = Loader::loadObj("objWithFacesAndVertices.obj", &vertices, &uvs, &normals, &triangles);

    EXPECT_TRUE(success);

    EXPECT_EQ(vertices.size(), 4);
    EXPECT_EQ(vertices[0], vec3(0, 0, 0));
    EXPECT_EQ(vertices[1], vec3(1, 0, 0));
    EXPECT_EQ(vertices[2], vec3(0, 1, 0));
    EXPECT_EQ(vertices[3], vec3(0, 0, 1));

    EXPECT_EQ(uvs.size(), 0);
    EXPECT_EQ(normals.size(), 0);

    EXPECT_EQ(triangles.size(), 4);
    EXPECT_EQ(triangles[0], Triangle(vec3(0, -1, -1), vec3(0, -1, -1), vec3(2, -1, -1)));
    EXPECT_EQ(triangles[1], Triangle(vec3(3, -1, -1), vec3(3, -1, -1), vec3(3, -1, -1)));
    EXPECT_EQ(triangles[2], Triangle(vec3(2, -1, -1), vec3(0, -1, -1), vec3(0, -1, -1)));
    EXPECT_EQ(triangles[3], Triangle(vec3(2, -1, -1), vec3(0, -1, -1), vec3(3, -1, -1)));

    remove("objWithFacesAndVertices.obj");
}

TEST(Loader, loadObjComplete) {
/* Create a file */
    ofstream file;
    file.open("objComplete.obj");
    file << "v 1.000000 -1.000000 -1.000000\n";
    file << "v 1.000000 -1.000000 1.000000\n";
    file << "v -1.000000 -1.000000 1.000000\n";
    file << "v -1.000000 -1.000000 -1.000000\n";
    file << "vt 0.748573 0.750412\n";
    file << "vt 0.749279 0.501284\n";
    file << "vt 0.999110 0.501077\n";
    file << "vt 0.999455 0.750380\n";
    file << "vn 0.000000 0.000000 -1.000000\n";
    file << "vn -1.000000 -0.000000 -0.000000\n";
    file << "vn -0.000000 -0.000000 1.000000\n";
    file << "vn -0.000001 0.000000 1.000000\n";
    file << "f 1/1/1 1/2/1 3/3/1\n";
    file << "f 4/1/1 4/3/1 4/4/1\n";
    file << "f 3/4/2 1/2/2 1/4/2\n";
    file << "f 3/1/2 1/2/2 4/3/2\n";
    file.close();

    vector<vec3> vertices;
    vector<vec2> uvs;
    vector<vec3> normals;
    vector<Triangle> triangles;

    bool success = Loader::loadObj("objComplete.obj", &vertices, &uvs, &normals, &triangles);

    EXPECT_TRUE(success);

    EXPECT_EQ(vertices.size(), 4);
    EXPECT_EQ(vertices[0], vec3(1, -1, -1));
    EXPECT_EQ(vertices[1], vec3(1, -1, 1));
    EXPECT_EQ(vertices[2], vec3(-1, -1, 1));
    EXPECT_EQ(vertices[3], vec3(-1, -1, -1));

    EXPECT_EQ(uvs.size(), 4);
    EXPECT_EQ(uvs[0], vec2(0.748573, 0.750412));
    EXPECT_EQ(uvs[1], vec2(0.749279, 0.501284));
    EXPECT_EQ(uvs[2], vec2(0.999110, 0.501077));
    EXPECT_EQ(uvs[3], vec2(0.999455, 0.750380));

    EXPECT_EQ(normals.size(), 4);
    EXPECT_EQ(normals[0], vec3(0, 0, -1));
    EXPECT_EQ(normals[1], vec3(-1, 0, 0));
    EXPECT_EQ(normals[2], vec3(0, 0, 1));
    EXPECT_EQ(normals[3], vec3(-1e-6, 0, 1));

    EXPECT_EQ(triangles.size(), 4);
    EXPECT_EQ(triangles[0], Triangle(vec3(0, 0, 0), vec3(0, 1, 0), vec3(2, 2, 0)));
    EXPECT_EQ(triangles[1], Triangle(vec3(3, 0, 0), vec3(3, 2, 0), vec3(3, 3, 0)));
    EXPECT_EQ(triangles[2], Triangle(vec3(2, 3, 1), vec3(0, 1, 1), vec3(0, 3, 1)));
    EXPECT_EQ(triangles[3], Triangle(vec3(2, 0, 1), vec3(0, 1, 1), vec3(3, 2, 1)));

    remove("objComplete.obj");
}

TEST(Loader, loadInvalidObjWithNegativeValuesInTriangleIndex) {
    ofstream file;
    file.open("invalidObjWithNegativeValuesInTriangleIndex.obj");
    file << "v 1.000000 -1.000000 -1.000000\n";
    file << "v 1.000000 -1.000000 1.000000\n";
    file << "v -1.000000 -1.000000 1.000000\n";
    file << "v -1.000000 -1.000000 -1.000000\n";
    file << "vt 0.748573 0.750412\n";
    file << "vt 0.749279 0.501284\n";
    file << "vt 0.999110 0.501077\n";
    file << "vt 0.999455 0.750380\n";
    file << "vn 0.000000 0.000000 -1.000000\n";
    file << "vn -1.000000 -0.000000 -0.000000\n";
    file << "vn -0.000000 -0.000000 1.000000\n";
    file << "vn -0.000001 0.000000 1.000000\n";
    file << "f -1/1/1 1/2/1 3/3/1\n";
    file << "f 4/1/1 4/3/1 4/4/1\n";
    file << "f 3/4/2 1/2/2 1/4/2\n";
    file << "f 3/1/2 1/2/2 4/3/2\n";
    file.close();

    vector<vec3> vertices;
    vector<vec2> uvs;
    vector<vec3> normals;
    vector<Triangle> triangles;

    bool success = Loader::loadObj("invalidObjWithNegativeValuesInTriangleIndex.obj", &vertices, &uvs, &normals, &triangles);

    EXPECT_FALSE(success);

    remove("invalidObjWithNegativeValuesInTriangleIndex.obj");
}


TEST(Loader, loadInvalidVertexWithLessThanThreeValues) {
    ofstream file;
    file.open("invalidVertexWithLessThanThreeValues.obj");
    file << "v 1.000000 -1.000000 -1.000000\n";
    file << "v 1.000000 -1.000000 -1.000000\n";
    file << "v -1.000000 -1.000000 1.000000\n";
    file << "v -1.000000 -1.000000\n";
    file << "vt 0.748573 0.750412\n";
    file << "vt 0.749279 0.501284\n";
    file << "vt 0.999110 0.501077\n";
    file << "vt 0.999455 0.750380\n";
    file << "vn 0.000000 0.000000 -1.000000\n";
    file << "vn -1.000000 -0.000000 -0.000000\n";
    file << "vn -0.000000 -0.000000 1.000000\n";
    file << "vn -0.000001 0.000000 1.000000\n";
    file << "f 1/1/1 1/2/1 3/3/1\n";
    file << "f 4/1/1 4/3/1 4/4/1\n";
    file << "f 3/4/2 1/2/2 1/4/2\n";
    file << "f 3/1/2 1/2/2 4/3/2\n";
    file.close();

    vector<vec3> vertices;
    vector<vec2> uvs;
    vector<vec3> normals;
    vector<Triangle> triangles;

    bool success = Loader::loadObj("invalidVertexWithLessThanThreeValues.obj", &vertices, &uvs, &normals, &triangles);

    EXPECT_FALSE(success);

    remove("invalidVertexWithLessThanThreeValues.obj");
}

TEST(Loader, loadInvalidVertexWithMoreThanThreeValues) {
    ofstream file;
    file.open("invalidVertexWithMoreThanThreeValues.obj");
    file << "v 1.000000 -1.000000 -1.000000\n";
    file << "v 1.000000 -1.000000 -1.000000\n";
    file << "v -1.000000 -1.000000 1.000000\n";
    file << "v -1.000000 -1.000000 -1.000000 1.000000\n";
    file << "vt 0.748573 0.750412\n";
    file << "vt 0.749279 0.501284\n";
    file << "vt 0.999110 0.501077\n";
    file << "vt 0.999455 0.750380\n";
    file << "vn 0.000000 0.000000 -1.000000\n";
    file << "vn -1.000000 -0.000000 -0.000000\n";
    file << "vn -0.000000 -0.000000 1.000000\n";
    file << "vn -0.000001 0.000000 1.000000\n";
    file << "f 1/1/1 1/2/1 3/3/1\n";
    file << "f 4/1/1 4/3/1 4/4/1\n";
    file << "f 3/4/2 1/2/2 1/4/2\n";
    file << "f 3/1/2 1/2/2 4/3/2\n";
    file.close();

    vector<vec3> vertices;
    vector<vec2> uvs;
    vector<vec3> normals;
    vector<Triangle> triangles;

    bool success = Loader::loadObj("invalidVertexWithMoreThanThreeValues.obj", &vertices, &uvs, &normals, &triangles);

    EXPECT_TRUE(success);
    EXPECT_EQ(vertices.size(), 4);
    EXPECT_EQ(vertices[0], vec3(1, -1, -1));
    EXPECT_EQ(vertices[1], vec3(1, -1, -1));
    EXPECT_EQ(vertices[2], vec3(-1, -1, 1));
    EXPECT_EQ(vertices[3], vec3(-1, -1, -1)); // Last value should be ignored

    remove("invalidVertexWithMoreThanThreeValues.obj");
}


TEST(Loader, loadInvalidUVWithLessThanTwoValues) {
    ofstream file;
    file.open("invalidUVWithLessThanTwoValues.obj");
    file << "v 1.000000 -1.000000 -1.000000\n";
    file << "v 1.000000 -1.000000 1.000000\n";
    file << "v -1.000000 -1.000000 1.000000\n";
    file << "v -1.000000 -1.000000 -1.000000\n";
    file << "vt 0.748573 0.750412\n";
    file << "vt 0.749279 0.501284\n";
    file << "vt 0.999110 0.501077\n";
    file << "vt 0.999455 0.750380\n";
    file << "vt 0.999455\n";
    file << "vn 0.000000 0.000000 -1.000000\n";
    file << "vn -1.000000 -0.000000 -0.000000\n";
    file << "vn -0.000000 -0.000000 1.000000\n";
    file << "vn -0.000001 0.000000 1.000000\n";
    file << "f 1/1/1 1/2/1 3/3/1\n";
    file << "f 4/1/1 4/3/1 4/4/1\n";
    file << "f 3/4/2 1/2/2 1/4/2\n";
    file << "f 3/1/2 1/2/2 4/3/2\n";
    file.close();

    vector<vec3> vertices;
    vector<vec2> uvs;
    vector<vec3> normals;
    vector<Triangle> triangles;

    bool success = Loader::loadObj("invalidUVWithLessThanTwoValues.obj", &vertices, &uvs, &normals, &triangles);

    EXPECT_FALSE(success);

    remove("invalidUVWithLessThanTwoValues.obj");
}

TEST(Loader, loadInvalidUVWithMoreThanTwoValues) {
    ofstream file;
    file.open("invalidUVWithMoreThanTwoValues.obj");
    file << "v 1.000000 -1.000000 -1.000000\n";
    file << "v 1.000000 -1.000000 1.000000\n";
    file << "v -1.000000 -1.000000 1.000000\n";
    file << "v -1.000000 -1.000000 -1.000000\n";
    file << "vt 0.748573 0.750412\n";
    file << "vt 0.749279 0.501284\n";
    file << "vt 0.999110 0.501077\n";
    file << "vt 0.999455 0.750380 0.999455\n";
    file << "vt 0.999455\n";
    file << "vn 0.000000 0.000000 -1.000000\n";
    file << "vn -1.000000 -0.000000 -0.000000\n";
    file << "vn -0.000000 -0.000000 1.000000\n";
    file << "vn -0.000001 0.000000 1.000000\n";
    file << "f 1/1/1 1/2/1 3/3/1\n";
    file << "f 4/1/1 4/3/1 4/4/1\n";
    file << "f 3/4/2 1/2/2 1/4/2\n";
    file << "f 3/1/2 1/2/2 4/3/2\n";
    file.close();

    vector<vec3> vertices;
    vector<vec2> uvs;
    vector<vec3> normals;
    vector<Triangle> triangles;

    bool success = Loader::loadObj("invalidUVWithMoreThanTwoValues.obj", &vertices, &uvs, &normals, &triangles);

    EXPECT_FALSE(success);

    remove("invalidUVWithMoreThanTwoValues.obj");
}

TEST(Loader, loadInvalidNormalWithLessThanThreeValues) {
    ofstream file;
    file.open("invalidNormalWithLessThanThreeValues.obj");
    file << "v 1.000000 -1.000000 -1.000000\n";
    file << "v 1.000000 -1.000000 1.000000\n";
    file << "v -1.000000 -1.000000 1.000000\n";
    file << "v -1.000000 -1.000000 -1.000000\n";
    file << "vt 0.748573 0.750412\n";
    file << "vt 0.749279 0.501284\n";
    file << "vt 0.999110 0.501077\n";
    file << "vt 0.999455 0.750380\n";
    file << "vn 0.000000 0.000000 -1.000000\n";
    file << "vn -1.000000 -0.000000 -0.000000\n";
    file << "vn -0.000000 -0.000000 1.000000\n";
    file << "vn -0.000001 0.000000 1.000000\n";
    file << "vn -0.000001 0.000000\n";
    file << "f 1/1/1 1/2/1 3/3/1\n";
    file << "f 4/1/1 4/3/1 4/4/1\n";
    file << "f 3/4/2 1/2/2 1/4/2\n";
    file << "f 3/1/2 1/2/2 4/3/2\n";
    file.close();

    vector<vec3> vertices;
    vector<vec2> uvs;
    vector<vec3> normals;
    vector<Triangle> triangles;

    bool success = Loader::loadObj("invalidNormalWithLessThanThreeValues.obj", &vertices, &uvs, &normals, &triangles);

    EXPECT_FALSE(success);

    remove("invalidNormalWithLessThanThreeValues.obj");
}

TEST(Loader, loadInvalidNormalWithMoreThanThreeValues) {
    ofstream file;
    file.open("invalidNormalWithMoreThanThreeValues.obj");
    file << "v 1.000000 -1.000000 -1.000000\n";
    file << "v 1.000000 -1.000000 1.000000\n";
    file << "v -1.000000 -1.000000 1.000000\n";
    file << "v -1.000000 -1.000000 -1.000000\n";
    file << "vt 0.748573 0.750412\n";
    file << "vt 0.749279 0.501284\n";
    file << "vt 0.999110 0.501077\n";
    file << "vt 0.999455 0.750380\n";
    file << "vn 0.000000 0.000000 -1.000000\n";
    file << "vn -1.000000 -0.000000 -0.000000\n";
    file << "vn -0.000000 -0.000000 1.000000\n";
    file << "vn -0.000001 0.000000 1.000000 1.000000\n";
    file << "vn -0.000001 0.000000\n";
    file << "f 1/1/1 1/2/1 3/3/1\n";
    file << "f 4/1/1 4/3/1 4/4/1\n";
    file << "f 3/4/2 1/2/2 1/4/2\n";
    file << "f 3/1/2 1/2/2 4/3/2\n";
    file.close();

    vector<vec3> vertices;
    vector<vec2> uvs;
    vector<vec3> normals;
    vector<Triangle> triangles;

    bool success = Loader::loadObj("invalidNormalWithMoreThanThreeValues.obj", &vertices, &uvs, &normals, &triangles);

    EXPECT_FALSE(success);

    remove("invalidNormalWithMoreThanThreeValues.obj");
}

TEST(Loader, loadInvalidTriangleWithLessThanThreeValues) {
    ofstream file;
    file.open("invalidTriangleWithLessThanThreeValues.obj");
    file << "v 1.000000 -1.000000 -1.000000\n";
    file << "v 1.000000 -1.000000 1.000000\n";
    file << "v -1.000000 -1.000000 1.000000\n";
    file << "v -1.000000 -1.000000 -1.000000\n";
    file << "vt 0.748573 0.750412\n";
    file << "vt 0.749279 0.501284\n";
    file << "vt 0.999110 0.501077\n";
    file << "vt 0.999455 0.750380\n";
    file << "vn 0.000000 0.000000 -1.000000\n";
    file << "vn -1.000000 -0.000000 -0.000000\n";
    file << "vn -0.000000 -0.000000 1.000000\n";
    file << "vn -0.000001 0.000000 1.000000\n";
    file << "f 1/1/1 1/2/1 3/3/1\n";
    file << "f 4/1/1 4/3/1 4/4/1\n";
    file << "f 3/4/2 1/2/2 1/4/2\n";
    file << "f 3/1/2 1/2/2 4/3/2\n";
    file << "f 3/1/2 1/2/2\n";
    file.close();

    vector<vec3> vertices;
    vector<vec2> uvs;
    vector<vec3> normals;
    vector<Triangle> triangles;

    bool success = Loader::loadObj("invalidTriangleWithLessThanThreeValues.obj", &vertices, &uvs, &normals, &triangles);

    EXPECT_FALSE(success);

    remove("invalidTriangleWithLessThanThreeValues.obj");
}

TEST(Loader, loadInvalidTriangleWithMoreThanThreeValues) {
    ofstream file;
    file.open("invalidTriangleWithMoreThanThreeValues.obj");
    file << "v 1.000000 -1.000000 -1.000000\n";
    file << "v 1.000000 -1.000000 1.000000\n";
    file << "v -1.000000 -1.000000 1.000000\n";
    file << "v -1.000000 -1.000000 -1.000000\n";
    file << "vt 0.748573 0.750412\n";
    file << "vt 0.749279 0.501284\n";
    file << "vt 0.999110 0.501077\n";
    file << "vt 0.999455 0.750380\n";
    file << "vn 0.000000 0.000000 -1.000000\n";
    file << "vn -1.000000 -0.000000 -0.000000\n";
    file << "vn -0.000000 -0.000000 1.000000\n";
    file << "vn -0.000001 0.000000 1.000000\n";
    file << "f 1/1/1 1/2/1 3/3/1 3/3/1\n";
    file << "f 4/1/1 4/3/1 4/4/1 4/4/1\n";
    file << "f 3/4/2 1/2/2 1/4/2 1/4/2\n";
    file << "f 3/1/2 1/2/2 4/3/2 4/3/2\n";
    file << "f 3/1/2 1/2/2 4/3/2 4/3/2 4/3/2\n";
    file.close();

    vector<vec3> vertices;
    vector<vec2> uvs;
    vector<vec3> normals;
    vector<Triangle> triangles;

    bool success = Loader::loadObj("invalidTriangleWithMoreThanThreeValues.obj", &vertices, &uvs, &normals, &triangles);

    EXPECT_TRUE(success);

    EXPECT_EQ(triangles.size(), 5);
    EXPECT_EQ(triangles[0], Triangle(vec3(0, 0, 0), vec3(0, 1, 0), vec3(2, 2, 0)));
    EXPECT_EQ(triangles[1], Triangle(vec3(3, 0, 0), vec3(3, 2, 0), vec3(3, 3, 0)));
    EXPECT_EQ(triangles[2], Triangle(vec3(2, 3, 1), vec3(0, 1, 1), vec3(0, 3, 1)));
    EXPECT_EQ(triangles[3], Triangle(vec3(2, 0, 1), vec3(0, 1, 1), vec3(3, 2, 1)));
    EXPECT_EQ(triangles[4], Triangle(vec3(2, 0, 1), vec3(0, 1, 1), vec3(3, 2, 1))); // Last value should be ignored

    remove("invalidTriangleWithMoreThanThreeValues.obj");
}

TEST(Loader, loadInvalidTriangleWithInvalidVertexIndex) {
    ofstream file;
    file.open("invalidTriangleWithInvalidVertexIndex.obj");
    file << "v 1.000000 -1.000000 -1.000000\n";
    file << "v 1.000000 -1.000000 1.000000\n";
    file << "v -1.000000 -1.000000 1.000000\n";
    file << "v -1.000000 -1.000000 -1.000000\n";
    file << "vt 0.748573 0.750412\n";
    file << "vt 0.749279 0.501284\n";
    file << "vt 0.999110 0.501077\n";
    file << "vt 0.999455 0.750380\n";
    file << "vn 0.000000 0.000000 -1.000000\n";
    file << "vn -1.000000 -0.000000 -0.000000\n";
    file << "vn -0.000000 -0.000000 1.000000\n";
    file << "vn -0.000001 0.000000 1.000000\n";
    file << "f 1/1/1 1/2/1 5/3/1\n";
    file << "f 4/1/1 4/3/1 4/4/1\n";
    file << "f 3/4/2 1/2/2 1/4/2\n";
    file << "f 3/1/2 1/2/2 4/3/2\n";
    file << "f 3/1/2 1/7/2 4/3/2\n";
    file.close();

    vector<vec3> vertices;
    vector<vec2> uvs;
    vector<vec3> normals;
    vector<Triangle> triangles;
    bool success = Loader::loadObj("invalidTriangleWithInvalidVertexIndex.obj", &vertices, &uvs, &normals, &triangles);

    EXPECT_FALSE(success);

    remove("invalidTriangleWithInvalidVertexIndex.obj");
}

TEST(Loader, loadInvalidTriangleWithOneMoreValueInFace) {
    ofstream file;
    file.open("invalidTriangleWithOneMoreValueInFace.obj");
    file << "v 1.000000 -1.000000 -1.000000\n";
    file << "v 1.000000 -1.000000 1.000000\n";
    file << "v -1.000000 -1.000000 1.000000\n";
    file << "v -1.000000 -1.000000 -1.000000\n";
    file << "vt 0.748573 0.750412\n";
    file << "vt 0.749279 0.501284\n";
    file << "vt 0.999110 0.501077\n";
    file << "vt 0.999455 0.750380\n";
    file << "vn 0.000000 0.000000 -1.000000\n";
    file << "vn -1.000000 -0.000000 -0.000000\n";
    file << "vn -0.000000 -0.000000 1.000000\n";
    file << "vn -0.000001 0.000000 1.000000\n";
    file << "f 1/1/1 1/2/1 3/3/1/1\n";
    file << "f 4/1/1 4/3/1 4/4/1\n";
    file << "f 3/4/2 1/2/2 1/4/2\n";
    file << "f 3/1/2 1/2/2 4/3/2\n";
    file << "f 3/1/2 1/2/2 4/3/2\n";
    file.close();

    vector<vec3> vertices;
    vector<vec2> uvs;
    vector<vec3> normals;
    vector<Triangle> triangles;
    bool success = Loader::loadObj("invalidTriangleWithOneMoreValueInFace.obj", &vertices, &uvs, &normals, &triangles);

    EXPECT_TRUE(success); //Values after the third will be ignored
    EXPECT_EQ(triangles[0], Triangle(vec3(0, 0, 0), vec3(0, 1, 0), vec3(2, 2, 0)));

    remove("invalidTriangleWithOneMoreValueInFace.obj");
}
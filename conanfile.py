from conan import ConanFile


class Recipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps", "VirtualRunEnv"

    def layout(self):
        self.folders.generators = "conan"

    def requirements(self):
        self.requires("asio/1.28.1")
        self.requires("sdbus-cpp/1.3.0")

    def build_requirements(self):
        self.test_requires("gtest/1.14.0")

#include <string>
namespace Bdv {
    class BdvScript {
    public:
        virtual int getArea() = 0;
        int width = 1440;
        int height = 900;
        int fps = 60;
        int logFps = 0;
        int debugShader = 0;
        int dimensions = 2;
        float tileSizeX = 16.0f;
        float tileSizeY = 16.0f;
        float* effects;
        std::string windowTitle = "Unnamed window";
        void init();
        void update(double deltaTime);
    protected:
        BdvScript() {
        }

    };
}
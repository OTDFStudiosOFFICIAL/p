#include <whb/gfx.h>
#include <whb/log.h>
#include <whb/log_console.h>
#include <coreinit/screen.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    // Initialize logging and graphics
    WHBLogConsoleInit();
    WHBGfxInit();

    // Flag to keep the app running
    int running = 1;

    // Main loop
    while (running) {
        // Start rendering on the TV
        WHBGfxBeginRenderTV();
        WHBGfxClearColor(0, 0, 0, 255); // Clear to black

        // Render letter "P" in the log console
        WHBLogPrint("P");

        // Finish rendering on the TV
        WHBGfxFinishRenderTV();
        WHBGfxSwapBuffers();

        // Start rendering on the GamePad
        WHBGfxBeginRenderDRC();
        WHBGfxClearColor(0, 0, 0, 255); // Clear to black

        // Render letter "P" in the log console
        WHBLogPrint("P");

        // Finish rendering on the GamePad
        WHBGfxFinishRenderDRC();
        WHBGfxSwapBuffers();

        // Draw the console log
        WHBLogConsoleDraw();

        // Optional: Add a way to exit if needed (e.g., polling for input)
        // For now, it runs infinitely
    }

    // Cleanup resources
    WHBGfxShutdown();
    WHBLogConsoleFree();

    return 0;
}

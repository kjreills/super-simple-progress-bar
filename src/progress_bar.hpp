#include <string>

namespace console {
    class progress_bar {
        std::string color;
        std::string incomplete_symbol = "\xE2\x96\x91";
        std::string complete_symbol = "\xE2\x96\x88";
        public: 
            // Create a progress bar with the default console color
            void init();

            // Create a progress bar with the specified color. Use the Console::Colors class defined color codes
            void init(std::string color);

            // Update the progress bar visual with the current state of the 
            void update(int percentComplete);
    };    
}

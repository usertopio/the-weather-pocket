    // Header files
    // Parent components
    #include "system.h" 
    // Child components
    #include "oledDisplay.h"
    #include "bme280.h"

    // Component instances
    // Buttons
    ButtonNext buttonNext(10);
    ButtonConfirm buttonConfirm(3);

    int y = 0;
    int gap = 0;

    // Constructor
    OledDisplay::OledDisplay(int oled_sda, int oled_scl,int screen_width, int screen_height, int address):   
        // Display configuration
        OLED_SDA(oled_sda),
        OLED_SCL(oled_scl),
        SCREEN_WIDTH(screen_width),
        SCREEN_HEIGHT(screen_height),
        ADDRESS(address),
        OLED_RESET(-1),
        // State
        state(State::WELCOME),
        // Libraries
        display(screen_width, screen_height, &Wire, OLED_RESET)
    {}

    // Initialization
    void OledDisplay::begin(){
        // Libraries
        Wire.begin(OLED_SDA, OLED_SCL);
        display.begin(SSD1306_SWITCHCAPVCC, ADDRESS);

        // State
        status = Status::ON;
    }

    // State
    OledDisplay::State OledDisplay::getState() const {
        return state;
    }

    void OledDisplay::setState(State newState) {
        state = newState;
    }

    void OledDisplay::updateDisplay(){
        buttonNext.readSignal();
        switch (getState())
        {
        case State::WELCOME:
            // Serial monitor
            Serial.println("Display: WELCOME");
            // Content
            display.clearDisplay();
            display.setTextSize(2);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(0, 0);
            display.print("WELCOME");
            display.display();
            // Check button next
            if (buttonNext.isButtonNextPressed())
            {
                setState(State::DISPLAY_WEATHER);
            }
            
            break;

        case State::DISPLAY_WEATHER:
            // Serial monitor
            Serial.println("Display: DISPLAY_WEATHER");
            // Content
            display.clearDisplay();
            display.setTextSize(2);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(0, 0);
            display.print("WEATHER");

            display.setTextSize(1);

            y = 20;     // starting Y
            gap = 12;   // <-- line spacing (increase for more space)

            display.setCursor(0, y);
            display.print("Temp: "); display.println(bme280.getTemp());

            y += gap;
            display.setCursor(0, y);
            display.print("Humid: "); display.println(bme280.getHumid());

            y += gap;
            display.setCursor(0, y);
            display.print("Pressure: "); display.println(bme280.getPressure());

            y += gap;
            display.setCursor(0, y);
            // display.print("Altitude: "); display.println(bme280.getAltitude());
            display.print("Gas: "); display.println(mq2.getRaw());

            display.display();

            // Check button next
            if (buttonNext.isButtonNextPressed())
            {
                setState(State::DISPLAY_LOCATION);
            }
            break;

        case State::DISPLAY_LOCATION:
            // Serial monitor
            Serial.println("Display: DISPLAY_LOCATION");
            // Content
            display.clearDisplay();
            display.setTextSize(2);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(0, 0);
            display.print("LOCATION");
            display.display();
            // Check button next
            if (buttonNext.isButtonNextPressed())
            {
                setState(State::DISPLAY_SETTING);
            }
            break;
        
        case State::DISPLAY_SETTING:
            // Serial monitor
            Serial.println("Display: DISPLAY_SETTING");
            // Content
            display.clearDisplay();
            display.setTextSize(2);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(0, 0);
            display.print("SETTING");
            display.display();
            // Check button next
            if (buttonNext.isButtonNextPressed())
            {
                setState(State::DISPLAY_WEATHER);
            }
            break;
        
        default:
            // Serial monitor
            Serial.println("Run out of oled display state!");
            setState(State::DISPLAY_WEATHER);
            break;
        }
    }
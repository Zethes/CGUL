/* Jatta - General Utility Library
 * Copyright (c) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Window.h"
#include <cstdio>
#include <sstream>

// Disable Warning C4355: 'this' : used in base member initializer list
// How we're using 'this' will not cause any undefined behavior
#pragma warning( disable : 4355 )

#ifdef WINDOWS
LRESULT CALLBACK Jatta::Window::WindowProcedure(HWND handle, UINT message, WPARAM wParam, LPARAM lParam)
{
    LONG_PTR ptr = GetWindowLongPtr(handle, GWLP_USERDATA);
    Window* window = (Window*)ptr;
    if (ptr != 0)
    {
        //window->getOnMessage()();
    }
    switch (message)
    {
        case WM_CLOSE:
        if (window != 0)
        {
            window->Close();
        }
        return 0;
        case WM_KEYDOWN:
        window->GetInput()->GetKeyData()[wParam] = true;
        return 0;
        case WM_KEYUP:
        window->GetInput()->GetKeyData()[wParam] = false;
        return 0;
        case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(handle, message, wParam, lParam);
}
#endif

#ifdef LINUX
std::map<Window, Jatta::Window*> Jatta::Window::windowMap;
Display* Jatta::Window::display;
bool Jatta::Window::initialized = false;

static int __jatta_windows_error_handler(Display* display, XErrorEvent* event)
{
    // TODO: something?
}
#endif

#ifdef MACOS
// Define the customized OpenGL view
@interface OpenGLView : NSOpenGLView
{
    // Create the timer capable of keeping up with delta time
    NSTimer* pTimer;
}
@end

// Define the cocoa application delegate
@interface AppDelegate : NSObject <NSApplicationDelegate, NSWindowDelegate>
{
    // The main application window
    NSWindow* window;

    // The customized OpenGL view
    OpenGLView* glView;

    // The window's default content
    id content;
}
@end

@implementation OpenGLView

    + (NSOpenGLPixelFormat*) defaultPixelFormat
    {
        // Set up the OpenGL view's attributes
        NSOpenGLPixelFormatAttribute attributes[] =
        {
            NSOpenGLPFAWindow,
            NSOpenGLPFADoubleBuffer,
            NSOpenGLPFADepthSize, (NSOpenGLPixelFormatAttribute)24,
            (NSOpenGLPixelFormatAttribute)nil
        };

        // Create our pixel format using the above attributes
        return [[[NSOpenGLPixelFormat alloc] initWithAttributes:attributes] autorelease];
    }

    - (void) idle: (NSTimer*)pTimer
    {
        static double lastTime = CFAbsoluteTimeGetCurrent();
        double time = CFAbsoluteTimeGetCurrent();
        float dt = float(time - lastTime);
        lastTime = time;
        //app->update(dt);
        glClearColor(255, 0, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        [[self openGLContext] flushBuffer];

        /*if (!*running)
        {
            [[self window] close];
        }*/
    }

    - (void) prepareOpenGL
    {
        // Set up the idle function call
        pTimer = [NSTimer timerWithTimeInterval:(1.0 / 60.0) target:self selector: @selector(idle:) userInfo:nil repeats:YES];
        [[NSRunLoop currentRunLoop]addTimer: pTimer forMode: NSDefaultRunLoopMode];

        // Initialize the application
        //app->initialize();
    }

@end

@implementation AppDelegate : NSObject

    - (id)init
    {
        // Initialize the base application and make sure it's not nil
        if (self = [super init])
        {
            // Define the size of the window
            NSRect frame = NSMakeRect(200, 200, 800, 600);

            // Define the style masks to be a titled window with close, max and min
            NSUInteger styleMask = NSTitledWindowMask | NSClosableWindowMask | NSMiniaturizableWindowMask/* | NSResizableWindowMask*/;

            // Adjust the window's sized based on the style mask
            NSRect rect = [NSWindow contentRectForFrameRect: frame styleMask: styleMask];

            // Create the window based on the above specifications
            window =  [[NSWindow alloc] initWithContentRect: rect styleMask: styleMask backing: NSBackingStoreBuffered defer: false];

            // Set the background color to black
            [window setBackgroundColor: [NSColor colorWithCalibratedRed: 0.0 green: 0.0 blue: 0.0 alpha: 1.0]];

            // Set the title of the window
            [window setTitle: @""];

            // Make this object the delegate for the window
            [window setDelegate: self];

            // Create an OpenGL view for the window
            glView = [[OpenGLView alloc] init];

            // Get the default content of the window
            content = [window contentView];

            // Set the content of the window to the OpenGL view we created
            [window setContentView: glView];

            // (TEMPORARILY) Make the window above all other windows
            [window setLevel: NSFloatingWindowLevel];

            // Set the application's window's data to the Cocoa window
            //appWindow->setData(window);
        }
        return self;
    }

    - (void)applicationWillFinishLaunching: (NSNotification*)notification
    {
        // Set the window front and foremost
        [window makeKeyAndOrderFront: self];
    }

    - (void)windowWillClose: (NSNotification*)aNotification
    {
        if (window != nil)
        {
            // Uninitialize the application
            //app->uninitialize();

            // Release the window
            [window release];
            window = nil;

            // Terminate the application when the window closes
            [NSApp terminate: self];
        }
    }

    - (void)windowDidResize: (NSNotification*)aNotification
    {
        // Set the view back to the original view temporarily
        [window setContentView: content];

        // Display the blank black window
        [window display];

        // Switch back to the OpenGL view once resizing is finished
        [window setContentView: glView];
    }

    - (void)dealloc
    {
        // Release the window and dealloc the super class
        [window release];
        [super dealloc];
    }
@end

int MyApplicationMain(int argc, const char **argv);

@interface MyApplication : NSApplication
{
    bool shouldKeepRunning;
}

- (void)run;
- (void)terminate:(id)sender;

@end

int MyApplicationMain(int argc, const char **argv)
{
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    
    NSDictionary *infoDictionary = [[NSBundle mainBundle] infoDictionary];
    Class principalClass =
        NSClassFromString([infoDictionary objectForKey:@"NSPrincipalClass"]);
    NSApplication *applicationObject = [principalClass sharedApplication];

    NSString *mainNibName = [infoDictionary objectForKey:@"NSMainNibFile"];
    NSNib *mainNib = [[NSNib alloc] initWithNibNamed:mainNibName bundle:[NSBundle mainBundle]];
    [mainNib instantiateNibWithOwner:applicationObject topLevelObjects:nil];

    if ([applicationObject respondsToSelector:@selector(run)])
    {
        [applicationObject
            performSelectorOnMainThread:@selector(run)
            withObject:nil
            waitUntilDone:YES];
    }
    
    [mainNib release];
    [pool release];
    
    return 0;
}

@implementation MyApplication

- (void)run
{
//  [self finishLaunching];
    [[NSNotificationCenter defaultCenter]
        postNotificationName:NSApplicationWillFinishLaunchingNotification
        object:NSApp];
    [[NSNotificationCenter defaultCenter]
        postNotificationName:NSApplicationDidFinishLaunchingNotification
        object:NSApp];
    
    shouldKeepRunning = YES;
}

-(bool) update
{
    NSEvent *event =
        [self
            nextEventMatchingMask:NSAnyEventMask
            untilDate:nil
            inMode:NSDefaultRunLoopMode
            dequeue:YES];
    
    NSLog(@"Hello world");
    [self sendEvent:event];
    [self updateWindows];
    return shouldKeepRunning;
}

- (void)terminate:(id)sender
{
    shouldKeepRunning = NO;
}

@end
#endif

_JATTA_EXPORT Jatta::Window::Window(const Window& copy) : input(this)
{
    /* deleted */
}

_JATTA_EXPORT Jatta::Window::Window(Window&& move) : input(this)
{
    /* deleted */
}

_JATTA_EXPORT void Jatta::Window::Update()
{
#   ifdef WINDOWS
    MSG Msg;
    while (PeekMessage(&Msg, nullptr, 0, 0, PM_REMOVE) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
#   endif

#   ifdef LINUX
    if (display)
    {
        while (XPending(display))
        {
            XEvent event;
            XNextEvent(display, &event);
            ::Window handle = event.xany.window;
            auto it = windowMap.find(handle);
            if (it == windowMap.end())
            {
                break;
            }
            Window* window = it->second;
            switch (event.type)
            {
                case 33:
                    XDestroyWindow(display, handle);
                case DestroyNotify:
                    window->Close();
                    return;
                case KeyPress:
                    window->GetInput()->GetKeyData()[window->GetInput()->GetKeyFromLayout(event.xkey.keycode)] = true;
                    break;
                case KeyRelease:
                    bool released = true;
                    if (XEventsQueued(display, QueuedAfterReading))
                    {
                        XEvent nextEvent;
                        XPeekEvent(display, &nextEvent);
                        if (nextEvent.type == KeyPress && nextEvent.xkey.time == event.xkey.time && nextEvent.xkey.keycode == event.xkey.keycode)
                        {
                            released = false;
                        }
                    }
                    if (released)
                    {
                        window->GetInput()->GetKeyData()[window->GetInput()->GetKeyFromLayout(event.xkey.keycode)] = false;
                    }
                    break;
            }
        }
    }
#   endif
}

_JATTA_EXPORT  Jatta::Window::Window() : input(this)
{
#   ifdef LINUX
    if (!initialized)
    {
        XSetErrorHandler(__jatta_windows_error_handler);
        display = XOpenDisplay(nullptr);
        initialized = true;
    }
#   endif
}

_JATTA_EXPORT Jatta::Window::~Window()
{
    Close();
}

#ifdef WINDOWS
_JATTA_EXPORT HWND Jatta::Window::_GetHandle()
{
    return handle;
}
#endif

#ifdef LINUX
_JATTA_EXPORT Display* Jatta::Window::_GetDisplay()
{
    return display;
}

_JATTA_EXPORT ::Window Jatta::Window::_GetHandle()
{
    return handle;
}
#endif

_JATTA_EXPORT Jatta::Input* Jatta::Window::GetInput()
{
    return &input;
}

_JATTA_EXPORT void Jatta::Window::Create(const WindowStyle& style)
{
#   ifdef WINDOWS
    // Generate a unique class name for this window
    std::wostringstream ss;
    static int windowCounter = 0;
    strcpy(className, "JATTA_");
    sprintf(className + 6, "%d", windowCounter++);
    ss << className;

    // Create the window class
    WNDCLASSEX wc;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0;
    wc.lpfnWndProc = WindowProcedure;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = GetModuleHandle(nullptr);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = CreateSolidBrush(RGB(style.backgroundColor.r, style.backgroundColor.g, style.backgroundColor.b));
    wc.lpszMenuName = NULL;
    wc.lpszClassName = new wchar_t[ss.str().length() + 1];
    memcpy((void*)wc.lpszClassName, ss.str().c_str(), sizeof(wchar_t) * (ss.str().length() + 1));
    wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);

    // Register the window class
    if (!RegisterClassEx(&wc))
    {
        throw std::runtime_error("Failed to register the window class.");
    }

    this->style = WS_OVERLAPPEDWINDOW;
    if (!style.resizable)
    {
        this->style &= ~WS_MAXIMIZEBOX;
        this->style &= ~WS_THICKFRAME;
    }

    RECT windowRect = {0, 0, (long)style.width, (long)style.height};
    AdjustWindowRectEx(&windowRect, this->style, false, WS_EX_CLIENTEDGE);

    handle = CreateWindowEx(WS_EX_CLIENTEDGE, wc.lpszClassName, style.title._ToWideString().c_str(), this->style, CW_USEDEFAULT, CW_USEDEFAULT, windowRect.right - windowRect.left, windowRect.bottom - windowRect.top, NULL, NULL, GetModule   Handle(nullptr), NULL);

    if (handle == NULL)
    {
        throw std::runtime_error("Failed to create the window!");
    }

    SetWindowLongPtr(handle, GWLP_USERDATA, (LONG_PTR)this);

    ShowWindow(handle, SW_SHOW);
#   endif

#   ifdef LINUX
    int screen = DefaultScreen(this->display);
    Visual* visual = DefaultVisual(this->display, screen);
    int depth = DefaultDepth(this->display, screen);
    XSetWindowAttributes attributes;
    attributes.background_pixel = style.backgroundColor.b | (style.backgroundColor.g << 8) | (style.backgroundColor.r << 16);//XWhitePixel(display, screen);
    attributes.border_pixel = XBlackPixel(this->display, screen);
    attributes.override_redirect = 0;
    this->handle = XCreateWindow(this->display, XRootWindow(this->display, screen), 200, 200, style.width, style.height, 5, depth, InputOutput, visual, CWBackPixel | CWBorderPixel | CWOverrideRedirect, &attributes);
    Atom wmDelete = XInternAtom(display, "WM_DELETE_WINDOW", true);
    XSetWMProtocols(this->display, this->handle, &wmDelete, 1);
    XSelectInput(this->display, this->handle, ExposureMask | ButtonPressMask | ButtonReleaseMask | KeyPressMask | KeyReleaseMask);
    XMapWindow(this->display, this->handle);
    XFlush(this->display);
    windowMap.insert(std::make_pair(this->handle, this));
#   endif

#   ifdef MACOS
    // Create an autorelease pool
    // There won't be many things in it from start to finish (since most everything is C++ side),
    // but it's still here for those few things that should be autoreleased!
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];

    // Create the Cocoa application
    MyApplication* application = [MyApplication sharedApplication];

    // Create our delegate as defined earlier in this file!
    AppDelegate* appDelegate = [[[AppDelegate alloc] init] autorelease];

    // Set the application delegate and run the application
    [application setDelegate: appDelegate];

    [application run];

    while (true)
    {
        std::cout << "asdf" << std::endl;
        [application update];
    }

    // Free anything we've autoreleased on the Obj-C side
    [pool drain];
#   endif
}

_JATTA_EXPORT void Jatta::Window::Close()
{
#   ifdef WINDOWS
    if (IsWindow(handle))
    {
        DestroyWindow(handle);
    }
    handle = 0;
#   endif

#   ifdef LINUX
    if (IsOpen())
    {
        XDestroyWindow(display, handle);
        XCloseDisplay(display);
    }
    handle = 0;
    display = nullptr;
#   endif
}

_JATTA_EXPORT void Jatta::Window::SetTitle(String title)
{
#   ifdef WINDOWS
	SetWindowText(handle, title._ToWideString().c_str());
#   endif

#   ifdef LINUX
    //TODO: Set Title for linux.
#   endif
}

_JATTA_EXPORT bool Jatta::Window::IsOpen() const
{
#   ifdef WINDOWS
    return IsWindow(handle) == TRUE;
#   endif

#   ifdef LINUX
    return display && handle;
#   endif
}

_JATTA_EXPORT unsigned int Jatta::Window::GetWidth() const
{
#   ifdef WINDOWS
    RECT rect = {0, 0, 0, 0};
    AdjustWindowRectEx(&rect, this->style, false, WS_EX_CLIENTEDGE);
    int borders = -rect.left + rect.right;
    GetWindowRect(handle, &rect);
    return rect.right - rect.left - borders;
#   endif

#   ifdef LINUX
    XWindowAttributes attributes;
    XGetWindowAttributes(display, handle, &attributes);
    return attributes.width;
#   endif
}

_JATTA_EXPORT unsigned int Jatta::Window::GetHeight() const
{
#   ifdef WINDOWS
    RECT rect = {0, 0, 0, 0};
    AdjustWindowRectEx(&rect, this->style, false, WS_EX_CLIENTEDGE);
    int borders = -rect.top + rect.bottom;
    GetWindowRect(handle, &rect);
    return rect.bottom - rect.top - borders;
#   endif

#   ifdef LINUX
    XWindowAttributes attributes;
    XGetWindowAttributes(display, handle, &attributes);
    return attributes.height;
#   endif
}

_JATTA_EXPORT Jatta::Float2 Jatta::Window::GetSize() const
{
    #   ifdef WINDOWS
    RECT rect = {0, 0, 0, 0};
    AdjustWindowRectEx(&rect, this->style, false, WS_EX_CLIENTEDGE);
    int borders = -rect.top + rect.bottom;
    GetWindowRect(handle, &rect);
    return Float2((float)(rect.right - rect.left - borders), (float)(rect.bottom - rect.top - borders));
#   endif

#   ifdef LINUX
    XWindowAttributes attributes;
    XGetWindowAttributes(display, handle, &attributes);
    return Float2(attributes.height, attributes.width);
#   endif
}

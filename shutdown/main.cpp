#include <iostream>
#include <Windows.h>
#include <nana/gui.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/label.hpp>
#include "scheduler.hpp"

void updateDisplayedTime(nana::label &label, const Time &time) {
    label.caption("<size=30>" + time.toString() + "</>");
}

int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char*, int nShowCmd) 
{
    Scheduler scheduler;

    nana::form fm;
    nana::drawing dw{ fm };
    
    fm.caption("Shutdown");
    fm.size(nana::size(515, 220));
    fm.bgcolor(nana::color(240, 240, 240));

    nana::label lb { fm, nana::rectangle{ 10, 10, 495, 50 } };
    lb.format(true);
    lb.text_align(nana::align::center);
    updateDisplayedTime(lb, scheduler.time());

    nana::button add1hour_btn{ fm, nana::rectangle{10, 80, 120, 70} };
    add1hour_btn.caption("+ 01:00");
    add1hour_btn.bgcolor(nana::color(255, 255, 255));
    add1hour_btn.typeface(nana::paint::font{ "Consolas", 14,{ 400 } }); 
    add1hour_btn.events().click([&lb, &scheduler] {
        scheduler.addTime(1, 0);
        updateDisplayedTime(lb, scheduler.time());
    });

    nana::button add30mins_btn{ fm, nana::rectangle{ 135, 80, 120, 70 } };
    add30mins_btn.caption("+ 00:30");
    add30mins_btn.bgcolor(nana::color(255, 255, 255)); 
    add30mins_btn.typeface(nana::paint::font{"Consolas", 14, {400}});
    add30mins_btn.events().click([&lb, &scheduler] {
        scheduler.addTime(0, 30);
        updateDisplayedTime(lb, scheduler.time());
    });

    nana::button add10mins_btn{ fm, nana::rectangle{ 260, 80, 120, 70 } };
    add10mins_btn.caption("+ 00:10");
    add10mins_btn.bgcolor(nana::color(255, 255, 255));
    add10mins_btn.typeface(nana::paint::font{ "Consolas", 14,{ 400 } }); 
    add10mins_btn.events().click([&lb, &scheduler] {
        scheduler.addTime(0, 10);
        updateDisplayedTime(lb, scheduler.time());
    });

    nana::button add5mins_btn{ fm, nana::rectangle{ 385, 80, 120, 70 } };
    add5mins_btn.caption("+ 00:05");
    add5mins_btn.bgcolor(nana::color(255, 255, 255)); 
    add5mins_btn.typeface(nana::paint::font{ "Consolas", 14,{ 400 } });
    add5mins_btn.events().click([&lb, &scheduler] {
        scheduler.addTime(0, 5);
        updateDisplayedTime(lb, scheduler.time());
    });

    nana::label schedule_btn{ fm, nana::rectangle{ 10, 160, 200, 40 } };
    schedule_btn.caption("Schedule shutdown");
    schedule_btn.fgcolor(nana::color(255, 255, 255));
    schedule_btn.bgcolor(nana::color(51, 153, 102));
    schedule_btn.text_align(nana::align::center, nana::align_v::center);
    schedule_btn.typeface(nana::paint::font{ "", 14,{ 400 } });
    schedule_btn.events().click([&lb, &scheduler] {
        scheduler.scheduleShutdown();
    });

    dw.draw([](nana::paint::graphics& graph) {
        graph.rectangle(nana::rectangle{ 8, 158, 203, 43 }, false, nana::color(250, 250, 250));
    });

    nana::label abort_btn{ fm, nana::rectangle{ 215, 160, 100, 40 } };
    abort_btn.caption("Abort");
    abort_btn.fgcolor(nana::color(255, 255, 255));
    abort_btn.bgcolor(nana::color(204, 41, 0));
    abort_btn.text_align(nana::align::center, nana::align_v::center);
    abort_btn.typeface(nana::paint::font{ "", 14,{ 400 } });
    abort_btn.events().click([&lb, &scheduler] {
        scheduler.abortShutdown();
    });

    dw.draw([](nana::paint::graphics& graph) {
        graph.rectangle(nana::rectangle{ 213, 158, 103, 43 }, false, nana::color(245, 245, 245));
    });

    nana::label reset_btn{ fm, nana::rectangle{ 320, 160, 90, 40 } };
    reset_btn.caption("Reset");
    reset_btn.fgcolor(nana::color(255, 255, 255));
    reset_btn.bgcolor(nana::color(166, 166, 166));
    reset_btn.text_align(nana::align::center, nana::align_v::center);
    reset_btn.typeface(nana::paint::font{ "", 14,{ 400 } });
    reset_btn.events().click([&lb, &scheduler] {
        scheduler.time().reset();
        updateDisplayedTime(lb, scheduler.time());
    });

    dw.draw([](nana::paint::graphics& graph) {
        graph.rectangle(nana::rectangle{ 318, 158, 93, 43 }, false, nana::color(245, 245, 245));
    });

    nana::label quit_btn{ fm, nana::rectangle{ 415, 160, 90, 40 } };
    quit_btn.caption("Exit");
    quit_btn.fgcolor(nana::color(255, 255, 255));
    quit_btn.bgcolor(nana::color(166, 166, 166));
    quit_btn.text_align(nana::align::center, nana::align_v::center);
    quit_btn.typeface(nana::paint::font{ "", 14,{ 400 } });
    quit_btn.events().click(nana::API::exit);

    dw.draw([](nana::paint::graphics& graph) {
        graph.rectangle(nana::rectangle{ 413, 158, 93, 43 }, false, nana::color(245, 245, 245));
    });

    dw.update();
    fm.show();
    nana::exec();
}
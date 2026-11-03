#import <UIKit/UIKit.h>
@interface CustomMenuViewController : UIViewController @end
@implementation CustomMenuViewController
(void)viewDidLoad { [super viewDidLoad];
// خلفية شفافة مع تأثير بصري self.view.backgroundColor = [[UIColor blackColor] colorWithAlphaComponent:0.75];
// إنشاء القائمة (UIView) UIView *menuBox = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 280, 200)]; menuBox.center = self.view.center; menuBox.backgroundColor = [UIColor colorWithRed:0.12 green:0.12 blue:0.15 alpha:1.0]; menuBox.layer.cornerRadius = 16; menuBox.layer.masksToBounds = YES;
// تأثير ظل أنيق menuBox.layer.shadowColor = [UIColor cyanColor].CGColor; menuBox.layer.shadowOpacity = 0.5; menuBox.layer.shadowRadius = 10.0;
// إضافة عنوان باسمك "إياد" UILabel *titleLabel = [[UILabel alloc] initWithFrame:CGRectMake(20, 20, 240, 40)]; titleLabel.text = @"✨ قائمة إياد المميزة ✨"; titleLabel.textColor = [UIColor whiteColor]; titleLabel.font = [UIFont boldSystemFontOfSize:18]; titleLabel.textAlignment = NSTextAlignmentCenter; [menuBox addSubview:titleLabel];
// إضافة زر إغلاق تفاعلي UIButton *closeBtn = [UIButton buttonWithType:UIButtonTypeSystem]; closeBtn.frame = CGRectMake(40, 130, 200, 40); [closeBtn setTitle:@"إغلاق القائمة" forState:UIControlStateNormal]; [closeBtn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal]; closeBtn.backgroundColor = [UIColor systemIndigoColor]; closeBtn.layer.cornerRadius = 10; [closeBtn addTarget:self action:@selector(closeMenu) forControlEvents:UIControlEventTouchUpInside]; [menuBox addSubview:closeBtn];
// تأثير حركة دخول القائمة (Animation) بعرض النافذة menuBox.transform = CGAffineTransformMakeScale(0.001, 0.001); [self.view addSubview:menuBox];
[UIView animateWithDuration:0.4 delay:0.0 usingSpringWithDamping:0.6 initialSpringVelocity:0.5 options:UIViewAnimationOptionCurveEaseInOut animations:^{ menuBox.transform = CGAffineTransformIdentity; } completion:nil]; }
(void)closeMenu { [self.view removeFromSuperview]; }
@end
// الدالة التلقائية لتشغيل القائمة فور الحقن attribute((constructor)) void initInjector() { dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(2.0 * NSEC_PER_SEC)), dispatch_get_main_projet ? : dispatch_get_main_queue(), ^{ UIWindow *window = [UIApplication sharedApplication].keyWindow; if (!window) { window = [[UIApplication sharedApplication].windows firstObject]; }
    CustomMenuViewController *menuVC = [[CustomMenuViewController alloc] init];
    menuVC.view.frame = window.bounds;
    [window addSubview:menuVC.view];
});
}

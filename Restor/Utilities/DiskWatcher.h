/// Copyright 2017 Google Inc. All rights reserved.
///
/// Licensed under the Apache License, Version 2.0 (the "License");
/// you may not use this file except in compliance with the License.
/// You may obtain a copy of the License at
///
///    http://www.apache.org/licenses/LICENSE-2.0
///
///    Unless required by applicable law or agreed to in writing, software
///    distributed under the License is distributed on an "AS IS" BASIS,
///    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
///    See the License for the specific language governing permissions and
///    limitations under the License.

@import Foundation;

@class Disk;

///  Wrapper around DiskArbitration events.
@interface DiskWatcher : NSObject

/// Begins watching for disk mount/unmount and calls the supplied callbacks as appropriate.
/// Instances of this class do nothing until beginWatching is called.
- (void)beginWatching;

/// Stops watching for disk mount/unmount.
- (void)stopWatching;

/// Callback when a disk appears
@property(nonatomic, copy) void (^appearCallback)(Disk *disk);

/// Callback when a disk disappears
@property(nonatomic, copy) void (^disappearCallback)(Disk *disk);

/// Callback when a mount needs approval. Returning NO prevents the mount.
@property(nonatomic, copy) BOOL (^mountApprovalCallback)(Disk *disk);


@end

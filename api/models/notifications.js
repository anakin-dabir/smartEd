import mongoose from 'mongoose';

const notificationSchema = new mongoose.Schema(
    {
        msg:String,
        sender:{ type: mongoose.Schema.Types.ObjectId, ref: 'User' },
        course : { type: mongoose.Schema.Types.ObjectId, ref: 'Course' },
        to:[{ type: mongoose.Schema.Types.ObjectId, ref: 'User' }]
    },
    {
        timestamps: true,
        collection: 'Notification'
    }
);
export default mongoose.model('Notifications', notificationSchema);

import mongoose from 'mongoose';

const courseSchema = new mongoose.Schema(
    {
        name:String,
        instructor: { type: mongoose.Schema.Types.ObjectId, ref: 'User' },
        details:String,
        content: [{ type: mongoose.Schema.Types.ObjectId, ref: 'Content' }],
        students:[{ type: mongoose.Schema.Types.ObjectId, ref: 'User' }]
    },
    {
        timestamps: true,
        collection: 'Course'
    }
);
export default mongoose.model('Course', courseSchema);